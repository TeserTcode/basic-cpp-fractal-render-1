int iter(double r,double i){
	int it=0;
	double temp;
	double rr=r;
	double ii=i;
	while(it<20 and r*r+i*i<4){
		temp=r;
		r=r*r-i*i+rr;
		i=2*temp*i+ii;
		it++;
		}
	
	
	
	return it;
}
