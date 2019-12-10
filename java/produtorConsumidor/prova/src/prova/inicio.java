package prova;

public class inicio {

	public static void main(String[] args) {
		
		bloQ fila = new bloQ(50);
		
		new Thread( new ProdutorConsumidor(fila, acao.produzir)).start();
		new Thread( new ProdutorConsumidor(fila, acao.produzir)).start();
		new Thread( new ProdutorConsumidor(fila, acao.produzir)).start();
		new Thread( new ProdutorConsumidor(fila, acao.produzir)).start();
		new Thread( new ProdutorConsumidor(fila, acao.produzir)).start();
		new Thread( new ProdutorConsumidor(fila, acao.produzir)).start();
		new Thread( new ProdutorConsumidor(fila, acao.produzir)).start();
		new Thread( new ProdutorConsumidor(fila, acao.produzir)).start();
		

		new Thread( new ProdutorConsumidor(fila, acao.consumir)).start();	
		new Thread( new ProdutorConsumidor(fila, acao.consumir)).start();	
		new Thread( new ProdutorConsumidor(fila, acao.consumir)).start();	
		new Thread( new ProdutorConsumidor(fila, acao.consumir)).start();	
		new Thread( new ProdutorConsumidor(fila, acao.consumir)).start();	
		new Thread( new ProdutorConsumidor(fila, acao.consumir)).start();	
		new Thread( new ProdutorConsumidor(fila, acao.consumir)).start();	
		new Thread( new ProdutorConsumidor(fila, acao.consumir)).start();	
		new Thread( new ProdutorConsumidor(fila, acao.consumir)).start();	

		
	}

}
