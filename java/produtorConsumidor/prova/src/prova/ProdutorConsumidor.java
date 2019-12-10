package prova;

import java.util.Random;

public class ProdutorConsumidor implements Runnable {
   
	bloQ fila;
	acao produzirConsumir;
	
	Random geradorNumeros;
	
	ProdutorConsumidor(bloQ fila,acao produzirConsumir){
		this.fila = fila;
		this.produzirConsumir = produzirConsumir;
		this.geradorNumeros =  new Random();
	}
	
	
	@Override
	public void run() {
		while(true)
		{	
			if(this.produzirConsumir == acao.produzir){
				int numeroRando  = geradorNumeros.nextInt(30);
				try {
					this.fila.push(numeroRando);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				System.out.println("inseriu : " + numeroRando);
				
			}else{
				int valorFila = 0;
				try {
				   valorFila = this.fila.pop();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				System.out.println("retiou: " + valorFila);
			}	
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}		
	}

}
