import Control.Concurrent
import Control.Monad
import Control.Concurrent.MVar
import Control.Concurrent.STM




produtorIngredientes pao carne queijo  = do 
                                        qtdPao <-  atomically $ readTVar pao
                                        qtdCarne <- atomically $ readTVar carne
                                        qtdQueijo <- atomically $ readTVar queijo
                                        atomically $ writeTVar queijo (qtdQueijo + 1)
                                        atomically $ writeTVar pao (qtdPao + 1)
                                        atomically $ writeTVar carne (qtdCarne + 1)                                        
                                        putStrLn("Produziu ingredientes")
                                        threadDelay 1000
                                        return()


consumidorSanduiche pao carne queijo faca = do 
                                        pegarFaca  <- takeMVar faca  -- pegou o privilegio de usar a  faca
                                        qtdPao <- atomically $ readTVar pao
                                        qtdCarne <- atomically $ readTVar carne
                                        qtdQueijo <- atomically $ readTVar queijo
                                        atomically $ writeTVar pao (qtdPao + 1)
                                        atomically $ writeTVar carne (qtdCarne + 1)
                                        atomically $writeTVar queijo (qtdQueijo + 1)
                                        putStrLn("fez um hamburguer")
                                        putMVar faca 1 -- liberou a faca
                                        threadDelay 1000



main  =  do 
      pao <- newTVarIO 0
      carne <- newTVarIO 0 
      queijo <- newTVarIO 0
      faca <- newEmptyMVar 
      putMVar faca 1
      forkIO $ forever $ produtorIngredientes pao carne queijo

      forkIO $ forever $ consumidorSanduiche pao carne queijo faca
      forkIO $ forever $ consumidorSanduiche pao carne queijo faca  
      
      return()