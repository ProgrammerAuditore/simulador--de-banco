bool fnc_FechaCorrecto(){
	
	// 21/21/2001
	int str = (int) strlen(user.FechaNacimiento);
	int BarraDiagonal = 0;
	int numeros = 0;
	
	if( (str - 1)  == 0 || (str - 1) != 10)
	{
		return(0);
	}else{
		
		for(int item=0; item < str; item++){
			if( isdigit(user.FechaNacimiento[item]) ){
				numeros++;
			}
			
			if( user.FechaNacimiento[item] == '/' ){
				BarraDiagonal++;	
			}
		}
		
		if( BarraDiagonal == 2 && numeros == 8 ){
			return(1);
		}else{
			return(0);
		}
		
	}
}