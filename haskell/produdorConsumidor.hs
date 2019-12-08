import Control.Concurrent
import Control.Monad
import Control.Concurrent.MVar
import Control.Concurrent.STM


-- produtor caixaPorca caixaParafuso = do
--                           qtdPorca <- atomically $ readTVar caixaPorca
--                           qtdParafuso <- atomically $ readTVar caixaParafuso
--                           atomically $ writeTVar caixaPorca (qtdPorca + 1)
--                           atomically $ writeTVar caixaParafuso (qtdParafuso + 1)
--                           putStrLn ("fez  = " ++ show(qtdPorca +1))
--                           threadDelay 100000
--                           return()
                          

produtorPorca caixaPorca = do 
                    qtdPorca <- atomically $ readTVar caixaPorca
                    atomically $ writeTVar caixaPorca (qtdPorca + 1)
                    --putStrLn("qtdPorca: " ++ show(qtdPorca + 1))
                    threadDelay 10000
                    return()

produtorParafuso caixaParafuso = do
                    qtdParafuso <- atomically $ readTVar caixaParafuso
                    atomically $ writeTVar caixaParafuso (qtdParafuso + 1)
                   -- putStrLn("qtdParafuso: " ++ show(qtdParafuso + 1))
                    threadDelay 10000
                    return()

consumidor  caixaPorca caixaParafuso caixaPorcaParafuso = do 
                                                    qtdCaixaPorcaparafuso <- takeMVar caixaPorcaParafuso --Pegando a quantidade de porca-parafusos feito e o privilegio de executar
                                                    qtdPorca <- atomically $ readTVar caixaPorca
                                                    qtdParafuso <- atomically $ readTVar caixaPorca
                                                    atomically $ writeTVar caixaPorca (qtdPorca - 1)
                                                    atomically $ writeTVar caixaParafuso (qtdParafuso - 1)
                                                    putMVar caixaPorcaParafuso (qtdCaixaPorcaparafuso + 1)
                                                    putStrLn("Consumiu : " ++ show(qtdParafuso))
                                                    putStrLn("Total porca-parafuso: " ++ show(qtdCaixaPorcaparafuso + 1))
                                                    threadDelay 100000
                                                    return()




main = do
  caixaPorca <-newTVarIO 0
  caixaParafuso <- newTVarIO 0  
  caixaPorcaParafuso <- newEmptyMVar
  putMVar caixaPorcaParafuso 0
  -- duas maquinas produzindo porca e parafuso
  forkIO $ forever $ produtorPorca caixaPorca
  forkIO $ forever $ produtorParafuso caixaParafuso
  
  forkIO $ forever $ consumidor caixaPorca caixaParafuso caixaPorcaParafuso
  forkIO $ forever $ consumidor caixaPorca caixaParafuso caixaPorcaParafuso
  return()

