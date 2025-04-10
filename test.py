# generate_ints.py
import sys
import random

def main():
    if len(sys.argv) < 2:
        print("Usage: python generate_ints.py <number_of_integers>")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("Error: The argument must be an integer.")
        sys.exit(1)

    if n <= 0:
        print("Error: The number of integers must be a positive integer.")
        sys.exit(1)

    nums = set()
    while len(nums) < n:
        val = random.getrandbits(32)  # 32ビットの非負整数 (0 ~ 2^32 - 1)
        # 上位ビットが立っていれば負に変換して、-2^31 ~ 2^31-1 の範囲にする
        if val >= 2**31:
            val -= 2**32
        nums.add(val)

    # 集合をリストにし、スペース区切りで一行に出力
    print(" ".join(map(str, nums)))

if __name__ == "__main__":
    main()
