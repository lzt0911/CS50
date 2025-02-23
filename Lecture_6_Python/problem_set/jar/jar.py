class Jar:
    def __init__(self, capacity=12):
        self.cur = 0
        self._capacity = 0
        if capacity >= 0:
            self._capacity = capacity
        else:
            raise ValueError("capacity can not be negative")

    def __str__(self):
        return "#" * self.cur

    def deposit(self, n):
        if self.cur + n > self._capacity:
            raise ValueError("Cannot deposit more than the jar's capacity")
        else:
            self.cur += n

    def withdraw(self, n):
        if self.cur - n < 0:
            raise ValueError("Cannot withdraw more than the jar's current amount")
        else:
            self.cur -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self.cur


def main():
    jar = Jar()
    print(str(jar.capacity))
    print(str(jar))
    jar.deposit(2)
    print(str(jar))
    jar.withdraw(1)
    print(str(jar))


main()
