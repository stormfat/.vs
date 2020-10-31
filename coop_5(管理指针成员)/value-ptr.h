#pragma once
class AHasPtr_value
{
 public:
  AHasPtr_value(int *p, int i):v_ptr(new int(*p)),v_val(i) {}
  AHasPtr_value(const AHasPtr_value &orig)
      : v_ptr(new int(*(orig.v_ptr))), v_val(orig.v_val) {}
  AHasPtr_value &operator=(const AHasPtr_value&);
  ~AHasPtr_value() { delete v_ptr; }
  int *getv_ptr() { return v_ptr; }
  int getv_val() { return v_val; }

  void setv_ptr(int *p) { v_ptr=p; }
  void setv_int(int i) { v_val = i; }

  int get_vptr_val() const { return *v_ptr; }
  void set_vptr_val(int val) const { *v_ptr = val; }
  
	  private:
		  int *v_ptr;
		  int v_val;
};

AHasPtr_value& AHasPtr_value::operator=(const AHasPtr_value& rhs) {
  *v_ptr = *rhs.v_ptr;
  v_val = rhs.v_val;
  return *this;

}