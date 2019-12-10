package prova;

public class bloQ {
	private int[] fila;
	private int  tamanho;
	
	public bloQ (int tamanho) {
		this.fila = new int[tamanho];
		this.tamanho = 0;
	}
	
	
	public synchronized  void push(int valor) throws InterruptedException {		
		while(this.tamanho == fila.length) {
			System.out.println("Fila esta cheia");
			wait();				
		}		
		this.fila[tamanho] = valor;	
		this.tamanho ++;
		notifyAll();		
	}
	
	public synchronized  int pop () throws InterruptedException {
		while(this.tamanho == 0) {
			System.out.println("fila esta vazia");
			wait();
		}		
		int retorno =  this.fila[0];
		for (int i = 0; i < tamanho-1; i++) {
			this.fila[i] = this.fila[i + 1];
		}			
		this.tamanho --;
		notifyAll();
		return  retorno;
	}
	
	
}
