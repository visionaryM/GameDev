class Tank:
    def __init__(self, name):
        self.name = name
        self.ammo = 5
        self.alive = True
        self.armor = 50
    def __str__(self):
        if self.alive:
            return "%s (%i armor, %i shells)" % (self.name, self.armor, self.ammo)
        else:
            return "%s (DEAD)" % (self.name)
    def fire_at(self, enemy):
        if self.ammo >=1:
            self.ammo -= 1
            print("%s fires on %s" % (self.name, enemy.name))
            enemy.hit()
        else:
            print("%s has no shells" % self.name)
            print("Reloading...")
            print("%s get hit while reloading"%self.name)
            self.reload()
    def hit(self):
        self.armor -= 10
        print("%s is hit"%self.name)
        if self.armor<=0:
            self.explode()
    def explode(self):
        self.alive = False
        print("%s explodes"%self.name)
    def reload(self):
        self.ammo = 5
        self.armor -= 10