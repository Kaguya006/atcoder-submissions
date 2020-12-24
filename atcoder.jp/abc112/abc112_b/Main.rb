n, t = gets.split.map(&:to_i)

ok = false
res = 1e6
n.times do |i|
  a, b = gets.split.map(&:to_i)
  if b <= t
    ok = true
    res = [res, a].min
  end
end

if ok
  puts res
else
  puts "TLE"
end
