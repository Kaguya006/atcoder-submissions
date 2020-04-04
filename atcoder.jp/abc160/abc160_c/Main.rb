k, n = gets.split(' ').map(&:to_i)
ary = gets.split(' ').map(&:to_i)

distance = []
(n).times do |i|
  dis = ary[(i + 1) % n] - ary[i]
  if dis < 0
    dis += k
  end
  distance[i] = dis
end

p (k - distance.max)
