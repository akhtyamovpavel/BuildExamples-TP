#include <string>


class FirstClass {
 public:
  std::string Get() const;
  void Set(const std::string& string);
 
 private:
  std::string string_;
};

