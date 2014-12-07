Big number
===========

In this task, you are going to write a C++ class to handle very large numbers. The following prototype is given.

class LLONG
{
  public:
    LLONG();
    LLONG(int);
    LLONG(const LLONG &);
    ~LLONG();
    void add(const LLONG &);
    void subtract(const LLONG &);
    void multiply(const LLONG &);
    void divide(const LLONG &);
    void mod(const LLONG &);
    std::ostream & output (std::ostream &);
    int compare(const LLONG &);
    // return 0 for equal, 1 for >, -1 for <
  private:
    ... // your design here
    ... // you are not allowed to use string here
};