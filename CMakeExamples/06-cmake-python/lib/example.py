from inheritance import Base


class Derived(Base):
    def f(self):
        return 42

    def g(self):
        return 1


class Derived2(Base):
    def f(self):
        return 44



if __name__ == '__main__':
    d = Derived()
    print(d.f())
    print(d.g())

    dd = Derived2()
    print(dir(dd))

    print(dd.f())
    print(dd.g())