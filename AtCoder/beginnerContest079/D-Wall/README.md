# ABC079 D-Wall
与えられる入力例を見れば、c_ijは「アッこれ10*10の隣接行列じゃん！」と気づくでしょう  
そう...つまりiからjまでの最短距離(通る辺の重みが最小)を求めれば良いのです  
というわけで、0〜9から1までの最短距離をそれぞれ求めておき、与えられたA_ijに0〜9があればその最短距離を積算していくことで、全てのA_ij (≠ -1)を1にするために必要な魔力が計算できます  
当たり前ですがA_ij = -1となっているところは空欄なので、無視します。

# ジャッジ結果
AC。コード長さ3092Byte, 実行時間9ms、メモリ384KB。