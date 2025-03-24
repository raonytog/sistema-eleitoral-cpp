all:
	clear
	@ make comp
	@ ./prog

comp: 
	g++ *.cpp -o prog

clean:
	rm -f *.o prog main SistemaEleitoral Candidato Partido Relatorios