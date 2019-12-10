
g x = varreLista x 0

varreLista (x:[]) n =  if n > 0  
                  then x:[] -- caso em que esta no ultimo numero e veio de uma repeticao 
                  else [] -- nao veio de repeticao


varreLista (x:y:xs)  n  =  if x == y   
                           then if n > 0 
                                then x:  varreLista (y:xs) (n+1) -- caso tenha vindo de uma repeticao ,concatene com o repetido
                                else varreLista (y:xs) (n+1) -- ignore o primeiro e some n 
                           else  if n > 0
                                 then x:varreLista (y:xs) 0
                                 else varreLista (y:xs) 0
                            