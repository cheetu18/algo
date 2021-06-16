def karatsuba_mult(val, val_b)
  if val < 10 || val_b < 10 
    return val * val_b
  end
  
  #compute 
  m2 = [val.to_s.length, val.to_s.length].max/2
  a, b = val.divmod(10**m2)
  c, d = val_b.divmod(10**m2)
  val1 = karatsuba_mult(a, c)
  val2 = karatsuba_mult(b, d)
  sum1 = a +  b 
  sum2 = c + d 
  val3 = karatsuba_mult(sum1, sum2) 
#  print val3 ,' ', sum1, ' ' , sum2 , "\n" 
  val3 = val3 - val1 - val2
  (2 * m2).times{ val1 *= 10 }    
  (m2).times{ val3 *= 10}
  return val1 + val2 + val3 
end


#puts karatsuba_mult(53333236, 13232)
puts karatsuba_mult(3141592653589793238462643383279502884197169399375105820974944592, 2718281828459045235360287471352662497757247093699959574966967627)
#puts karatsuba_mult(56, 12)
#puts karatsuba_mult(78, 34)
#puts karatsuba_mult(134, 46)
#puts karatsuba_mult(5678, 1234)

