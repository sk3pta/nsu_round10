

s = '''5F 00 00 00 02 48 57 00 0E 00 00 00 48 65 6C 6C
6F 2C 20 57 6F 72 6C 64 21 00 02 D0 9F 20 D0 9C
00 17 00 00 00 D0 9F D1 80 D0 B8 D0 B2 D0 B5 D1
82 20 D0 B2 D1 81 D0 B5 D0 BC 21 00 01 64 62 6C
00 66 66 66 66 66 BA 81 40 10 69 6E 74 00 25 00
00 00 0A 6E 6F 6E 65 00 08 62 6C 6C 00 01 00'''


with open("i","w") as file:
    for b in s.split(" "):
        file.write(f"{b}\n")
