s = gets.chomp!
k = gets.to_i
ary = []
for i in 0...(s.length)
  t = s[i]
  ary.push(t.dup)
  (k - 1).times do |j|
    if (i + j + 1) < s.length then
      t << s[i + j + 1]
      ary.push(t.dup)
    end
  end
end

ary.select!{|v| v.size == k}
ary.uniq!
puts ary.size
