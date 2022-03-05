import random, struct
low = 0
high = 10000000

chaos = open("/dev/urandom", "rb")
magic = chaos.read(8)
chaos.close()
magic = int(struct.unpack("<Q", magic)[0])
random.seed(magic)

def rand():
    return random.randint(low, high)

fd = open("./testcase", "w")

num = rand() % 1000
chain = ''
for i in range(1000000):
    num+=rand()%1000
    chain+=str(num)+' '
chain+='\n'

num+=1000000
for i in range(1000000):
    num-=rand()%1000
    chain+=str(num)+' '
chain+='\n'

for i in range(8):
    for j in range(1000000):
        num = rand()
        chain+=str(num)+' '
    chain+='\n'
fd.write(chain)
fd.close()