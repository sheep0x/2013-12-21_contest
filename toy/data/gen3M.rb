#! /usr/bin/env ruby

Nmin, Nmax, Mmin, Mmax = ARGV.collect {|a| a.to_i}

N = rand(Nmax-Nmin+1) + Nmin
puts N
(N*20).times { puts( ['M', rand(N)+1, rand(N)+1].join ' ' ) }
