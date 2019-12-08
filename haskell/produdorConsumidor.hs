import Control.Concurrent
import Control.Monad
import Control.Concurrent.MVar
import Control.Concurrent.STM


produtor caixaPorca caixaParafuso = do
                          qtdPorca <- atomically $ readTVar caixaPorca
                          qtdParafuso <- atomically $readTVar caixaParafuso
                          atomically $ writeTVar caixaPorca (qtdPorca + 1)
                          atomically $ writeTVar caixaParafuso (qtdParafuso + 1)
                          putStrLn ("Quantidade porca = " ++ show(qtdPorca +1))


consumidor  caixaPorca caixaParafuso caixaPorcaParafuso do 
                                                    

main = do
  caixaPorca <-newTVarIO 0
  caixaParafuso <- newTVarIO 0  
  caixaPorcaParafuso <- newEmptyMVar
  qtdPorca <- atomically $ readTVar caixaPorca
  forkIO $ forever $ produtor caixaPorca caixaParafuso
  return()

