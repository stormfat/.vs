#include <stdio.h>

#include <iostream>
#include <string>
using namespace std;
class BadSrcFile {
 public:
  BadSrcFile() { cout << "打开源文件错误\n" << endl; }
};
class BadDestFile {
 public:
  BadDestFile() { cout << "打开目标文件错误\n" << endl; }
};
class BadCopy {
 public:
  BadCopy() { cout << "拷贝错误\n" << endl; }
};

int my_cp(const char* src_file, const char* dest_file) {
  FILE *in_file, *out_file;
  in_file = fopen(src_file, "rb");
  if (in_file == NULL) {
    return 1;  //传统的异常处理方式,当有错误发生,返回一个非0数.
  }
  out_file = fopen(dest_file, "wb");
  if (out_file == NULL) {
    return 2;
  }
  char rec[256];
  size_t bytes_in, bytes_out;
  bytes_in = fread(rec, 1, 256, in_file);
  while (bytes_in > 0) {
    cout << "copy..." << endl;
    bytes_out = fwrite(rec, 1, bytes_in, out_file);
    if (bytes_in != bytes_out) {
      return 3;
    }
    bytes_in = fread(rec, 1, 256, in_file);
  }
  fclose(in_file);
  fclose(out_file);
  return 0;
}

int my_cp2(const char* src_file, const char* dest_file) {
  FILE *in_file, *out_file;
  in_file = fopen(src_file, "rb");
  if (in_file == NULL) {
    throw "打开源文件出错\n";  //抛出异常.
  }
  out_file = fopen(dest_file, "wb");
  if (out_file == NULL) {
    throw "打开目的文件出错\n";
  }
  char rec[256];
  size_t bytes_in, bytes_out;
  bytes_in = fread(rec, 1, 256, in_file);
  while (bytes_in > 0) {
    cout << "copy..." << endl;
    bytes_out = fwrite(rec, 1, bytes_in, out_file);
    if (bytes_in != bytes_out) {
      throw "写文件出错\n";
    }
    bytes_in = fread(rec, 1, 256, in_file);
  }
  fclose(in_file);
  fclose(out_file);
  return 0;
}

int my_cp3(const char* src_file, const char* dest_file) {
  FILE *in_file, *out_file;
  in_file = fopen(src_file, "rb");
  if (in_file == NULL) {
    throw BadSrcFile();  //抛出异常.
  }
  out_file = fopen(dest_file, "wb");
  if (out_file == NULL) {
    throw BadCopy();
  }
  char rec[256];
  size_t bytes_in, bytes_out;
  bytes_in = fread(rec, 1, 256, in_file);
  while (bytes_in > 0) {
    cout << "copy..." << endl;
    bytes_out = fwrite(rec, 1, bytes_in, out_file);
    if (bytes_in != bytes_out) {
      throw BadCopy();
    }
    bytes_in = fread(rec, 1, 256, in_file);
  }
  fclose(in_file);
  fclose(out_file);
  return 0;
}

/*my_cp用返回的错误代码捕捉异常,C传统的异常捕捉方式.
  my_cp2用抛出字符串的方式,通过try..catch捕捉异常
  my_cp3用抛出类的方式,通过try..catch捕捉异常*/
int main() {
  int result;
  if ((result = my_cp("1.txt", "2.txt")) != 0) {
    switch (result) {
      case 1:
        cout << "打开源文件出错\n";
        break;
      case 2:
        cout << "打开目的文件出错\n";
        break;
      case 3:
        cout << "写文件出错\n";
        break;
      default:
        cout << "发生未知错误\n";
        break;
    }
  }
  try {
    my_cp2("1.txt", "3.txt");
    my_cp3("112.txt", "3.txt");
  } catch (const char* e) {
    cout << e << endl;
  } catch (BadSrcFile e) {
    e;
  } catch (BadDestFile e) {
    e;
  } catch (BadCopy e) {
    e;
  } catch (...) {  //捕获上面没有提到的所有异常
    cout << "未知异常" << endl;
  }
  cout << "ok\n";
  return 0;
}
