class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n + 1)]

    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]
    
    def same(self, x, y):
        return self.find(x) == self.find(y)

    def unite(self, x, y):
        X = self.find(x)
        Y = self.find(y)

        if X == Y:
            return 0
        
        self.par[X] = y

n, q = map(int, input().split())
uf = UnionFind(n)
for i in range(q):
    p, a, b = map(int, input().split())

    if p == 0:
        uf.unite(a, b)
    else:
        if uf.same(a, b):
            print("Yes")
        else:
            print("No")

