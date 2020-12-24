h, w = gets.split.map(&:to_i)
ary = h.times.map { gets.split.map(&:to_i) }
ary.flatten!
p ary.sum - ary.min * ary.size
