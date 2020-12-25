s = gets.chomp
t = gets.chomp

s.length.times do |i|
  str = ""
  i.upto(i + s.length - 1) do |j|
    str += s[j %  s.length]
  end

  if str == t then
    puts "Yes"
    exit(true)
  end
end

puts "No"


