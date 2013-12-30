#! /usr/bin/env ruby

Nmin, Nmax, Qmin, Qmax, Merges = ARGV.collect {|a| a.to_i}

N = $stdin.gets.to_i
Q = rand(Qmax-Qmin+1) + Qmin
m = []
$stdin.each_line {|x| m<<x}

puts N
cnt=0
for op in ( Array.new(Merges-1) + Array.new(Q) {"Q #{rand(N)+1} #{rand(N)+1}"} ).shuffle
  if op
    puts op
  else
    puts m[cnt]
    cnt+=1
  end
end
puts m[cnt]
