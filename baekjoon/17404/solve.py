def dp_counter(prev, price):
  arr = [0, 0, 0]
  for i in range(0, 3):
    if prev[i] == 0:
      if i == 0:
        arr[i] = price[i] + min(prev[1], prev[2])
      elif i == 1:
        arr[i] = price[i] + min(prev[0], prev[2])
      elif i == 2:
        arr[i] = price[i] + min(prev[0], prev[1])
  return arr

N = int(input())

price = [list(map(int, input().split(' '))) for i in range(0, N)]

r_dp = [[0, 0, 0] for i in range(0, N - 1)]
g_dp = [[0, 0, 0] for i in range(0, N - 1)]
b_dp = [[0, 0, 0] for i in range(0, N - 1)]

if(N == 2):
  print(min(price[0][0] + min(price[1][1], price[1][2]), price[0][1] + min(price[1][0], price[1][2]), price[0][2] + min(price[1][0], price[1][1])))
  exit()

r_dp[0] = price[0]
g_dp[0] = price[0]
r_dp[0] = price[0]

r_dp[1] = [0, r_dp[0][0] + price[1][1], r_dp[0][0] + price[1][2]]
g_dp[1] = [g_dp[0][1] + price[1][0], 0, g_dp[0][1] + price[1][2]]
b_dp[1] = [b_dp[0][2] + price[1][0], b_dp[0][2] + price[1][1] + price[1][1], 0]

for i in range(3, N-1):
  for j in range(0, 3):
    if j == 0:
    elif j == 1:
    else:

print(min(r_dp[N - 1]), min(g_dp[N - 1]), min(b_dp[N - 1]))