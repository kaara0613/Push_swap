#!/usr/bin/env python3
import sys
import random

def main():
    # 0～INT_MAXの範囲で生成する整数の個数を引数で指定
    if len(sys.argv) < 2:
        print("Usage: python3 program.py <number_of_integers>")
        sys.exit(1)
    
    try:
        count = int(sys.argv[1])
    except ValueError:
        print("Error: 引数は整数で指定してください。")
        sys.exit(1)

    if count < 0:
        print("Error: 生成する数は0以上の整数で指定してください。")
        sys.exit(1)

    # 定義：C言語のINT_MAX = 2^31 - 1
    INT_MAX = 2**31 - 1

    # 0からINT_MAXまでのすべての数は INT_MAX+1 個
    if count > INT_MAX + 1:
        print(f"Error: 生成数は {INT_MAX + 1} 個以下にしてください。")
        sys.exit(1)

    # random.sample は range オブジェクトから直接サンプル抽出できる
    result = random.sample(range(0, INT_MAX + 1), count)

    # スペース区切りで出力
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()
