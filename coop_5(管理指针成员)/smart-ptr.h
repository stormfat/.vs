#pragma once
class U_Ptr
{
  friend class BHasPtr;
 private:
  int *ip;
  size_t use;//计数
  U_Ptr(int *p) : ip(p), use(1){}

 public:
  ~U_Ptr() { delete ip; }

};
class BHasPtr {
 public:
  BHasPtr(int *p, int i) : ptr(new U_Ptr(p)), val(i) {}

  int *get_ptr() const { return ptr->ip; }
  int get_int() const { return val; }

  void set_ptr(int *p) { ptr->ip = p; }
  void set_int(int i) { val = i; }

  int get_ptr_val() const { return *ptr->ip; }
  int set_ptr_val(int val) const { return *(ptr->ip)= val; }

  BHasPtr(const BHasPtr &orig) : ptr(orig.ptr), val(orig.val) { ++(ptr->use); }
  ~BHasPtr() {
    if (--(ptr->use) == 0) delete ptr;
  }

  BHasPtr &operator=(const BHasPtr &);

 private:
  int val;
  U_Ptr *ptr;
};

BHasPtr &BHasPtr::operator=(const BHasPtr &rhs) {
  ++rhs.ptr->use;
 if (--ptr->use == 0) delete ptr;
  ptr = rhs.ptr;
  val = rhs.val;
  return *this;
}