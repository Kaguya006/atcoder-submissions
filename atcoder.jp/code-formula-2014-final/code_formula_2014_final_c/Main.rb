S = gets.split
ary = []

for s in S do
  if s.size > 1 then
    i = 1
    t = ""
    
    while (i < s.length && (s[i - 1] != '@' || s[i] == '@')) do
      i += 1
    end
    
    while (i < s.length && s[i - 1] == '@' && s[i] != '@') do
      t += s[i]
      while (i + 1 < s.length && s[i + 1] != '@') do
        i += 1
        t += s[i]
      end
      
      ary.push(t)

      i += 2
      while (i < s.length && (s[i - 1] != '@' || s[i] == '@')) do
        i += 1
      end
      t = ""
    end
    
  end
end

ary.uniq!
ary.sort!

for ans in ary do
  puts ans
end
