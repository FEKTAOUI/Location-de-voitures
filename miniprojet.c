#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Voiture
{ 
 int   idVoiture; 
 char  marq[15]; 
 char  nomVoiture[15]; 
 char  couleur[7]; 
 int   nbplaces; 
 int prixparJour; 
 char  EnLocation[4]; 
}voiture; 
 
 voiture info;

typedef struct{
	int jour;
	int mois;
	int ans;
}date;

typedef struct contratLocation 
{ 
 int numContrat; 
 int idVoiture; 
 int idClient; 
 date debut; 
 date fin; 
 int cout; 
} contrat;

typedef struct Client
{ 
 int idClient; 
 char nom[10]; 
 char prenom[15]; 
 char cin[12]; 
 char adresse[20]; 
 int phone; 
}cliente;


 
                                     //**********prototype des  fonctions dE RECHERCHE*********|   
									           
                                                 
                                        int rech(int idrech);  //recherche dans le fichier voiture sur id d'un voiture, return 1 c'est le voiture exist sinon return 0.
                                                
										int rechchar(int id);   //recherche dans le fichier voiture ,return 1 c'est le id de voiture exist et pas louer sinon return 0.
                                                
										int rechidclient(int idrech);  //recherche dans le fichier client ,return 1 c'est le client exist  sinon return 0 .
  
 
 
 
 
                                        //********fonction de recherche dans le fichier sur id de voiture.
                                
								        
  int rech(int idrech){
  	FILE *F;
  	F=fopen("voiture.txt","r");
  voiture info;	
	while(!feof(F)){
  	fscanf(F,"%d %s %s %s %d %d %s",&info.idVoiture,&info.nomVoiture,&info.couleur,&info.marq,&info.nbplaces,&info.prixparJour,&info.EnLocation);
  	if(info.idVoiture==idrech){
  	 return 1;
  	 break;
	 }
	  }
	  return 0;
	  fclose(F);
	  
  }
  
  
  
  
  
                                        //*********fonction de recherche dans le fichier sur id de voiture.
                                        
                                
    int rechchar(int id){
  	FILE *F;
  	int q;
  	F=fopen("voiture.txt","r");
  	voiture info;	
	while(!feof(F)){
	  	fscanf(F,"%d %s %s %s %d %d %s",&info.idVoiture,&info.nomVoiture,&info.couleur,&info.marq,&info.nbplaces,&info.prixparJour,&info.EnLocation);
        if(info.idVoiture==id){
	 	q=strcmp(info.EnLocation,"NO");
  		if(q==0){
  				return 1;
  				break;
		  }
	   }
	}
	  return 0;
      fclose(F);
  }
  
  
  
  
  
                                        //********fonction de recherche dans le fichier sur id de client.
                                        

                           
  int rechidclient(int idrech){
  	FILE *F;
  	F=fopen("client.txt","r");
  cliente info;	
	while(!feof(F)){
    fscanf(F,"%d %s %s %s %s %d",&info.idClient,&info.nom,&info.prenom,&info.cin,&info.adresse,&info.phone);
  	if(info.idClient==idrech){
  	fclose(F);
  	return 1;
  	break;
		}		
	}
    return 0;
	fclose(F);
  }                                        
                             
							 
							 
							            
								//**********prototype des  fonctions du Gestion des voitures*********|
								
  											void  listevoiture(FILE *F);
  											
 									    	void  ajoutevoiture(FILE *F);	
 									    	
                                            void  supprimervoiture(FILE*F);
                                      
									        int   nblign(FILE *F,const char *name);  // calculer le nombre de ligne d'un fichier pour utilisez comme taille d'un tableux.
                                         
										    void  modifiervoiture(FILE*F);






                                                     /**   ************liste info de voitures************   **/
      
      
 void  listevoiture(FILE *F){
 	printf("\n\n");
 	char ch;
 	F=fopen("voiture.txt","r");
 	ch=fgetc(F);
 	printf("id de voiture|le nom de voiture|colour de voiture|Nomber de place|la marque  de voiture|prix par jour |Enlocation\n");
while(ch!=EOF)
 		{	printf("%c",ch);
 			ch=fgetc(F);
		 
		 }
 }
 
  
   	
	   
	   
	   								        		 /**   ************ajouter info d'un voiture************   **/
  
  
  void ajoutevoiture(FILE *F){
  	int i,n,k,nb;
  	printf("\n\n\n\n");
  	listevoiture(F);
  	printf("\n\n************************avant ajouter*********************************\n\n");
  	
  	printf("              ********ajouter de voitures********");
  	 F=fopen("voiture.txt","a");
	voiture *tabvoiture,*pvoiture;
    printf("\n\n");
    printf("              le nombre des voitures :");
    scanf("%d",&n);
    fflush(stdin);
    tabvoiture=(voiture*)malloc(n*sizeof(voiture));
    printf("\n\n");
    for(pvoiture=tabvoiture;pvoiture<tabvoiture+n;pvoiture++){
    printf("                  ******la voiture %d******",pvoiture-tabvoiture+1);
    printf("\n\n");
    printf("                  ->id de voiture....................:");
    scanf("%d",&nb);
	k=rech(nb);
    while(k==1){
  	printf("\n               ************ce number exist deja***********");
    printf("\n                  ->id de voiture....................:");
    scanf("%d",&nb);
     k=rech(nb);
	  }
	pvoiture->idVoiture=nb;
    printf("                  ->le nom de voiture................:");
    scanf("%s",&pvoiture->nomVoiture);
    fflush(stdin);
    printf("                  ->colour de voiture................:");
    scanf("%s",&pvoiture->couleur);
    fflush(stdin);
    printf("                  ->la marque  de voiture............:");
    scanf("%s",&pvoiture->marq);
	fflush(stdin);
    printf("                  ->Nomber de place..................:");
    scanf("%d",&pvoiture->nbplaces);
    fflush(stdin);
    printf("                  ->prix par jour de voiture.........:");
    scanf("%d",&pvoiture->prixparJour);
    fflush(stdin);
    printf("                  ->Enlocation Oui/No................:");
    scanf("%s",&pvoiture->EnLocation);

    fprintf(F,"\n%d        %s        %s        %s        %d        %d        %s",pvoiture->idVoiture,pvoiture->nomVoiture,pvoiture->couleur,pvoiture->marq,pvoiture->nbplaces,pvoiture->prixparJour,pvoiture->EnLocation);
   printf("\n\n");
   }
   fclose(F);
   	printf("\n\n************************apres ajouter*********************************\n\n");
   listevoiture(F);
  }
  
           
		   
		   
		   
		                                      		     /**   ************supprimer info d'un voiture************   **/		   
		   
		   
		   
void supprimervoiture(FILE*F){
	int idvoiture,nbl,i,k;
	char reponse;
	listevoiture(F);
	nbl=nblign(F,"voiture.txt");
	F = fopen("voiture.txt","r");
	voiture *tab,*pt;
	tab=(voiture*)malloc(nbl*sizeof(voiture));
	printf("\n\n************************avant supprimer*********************************\n\n\n");
	printf("\n \n\n****!!!!!!!!!vous veuillez vraiment faire c'est operation O/N:");
	scanf("%c",&reponse);
	if(reponse=='o' || reponse=='O'){
	for(pt=tab;pt<tab+nbl;pt++){
		fscanf(F,"%d %s %s %s %d %d %s",&pt->idVoiture,&pt->nomVoiture,&pt->couleur,&pt->marq,&pt->nbplaces,&pt->prixparJour,&pt->EnLocation);
	}
	fclose(F);
	printf("\n\n");
	printf("veuillez entrer le id a supprimer : ");
	scanf("%d",&idvoiture);
	printf("\n");
	k=rech(idvoiture);
	while(k!=1){
  	printf("\n               ************ce number n'exist Pas***********");
    printf("\n\n veuillez entrer le id a supprimer : ");
	scanf("%d",&idvoiture);
     k=rech(idvoiture);
	  }
	F=fopen("voiture.txt","w");
	for(pt=tab;pt<tab+nbl;pt++){
		if(pt->idVoiture==idvoiture){
			
		}
		else fprintf(F,"\n%d       %s       %s       %s       %d       %d       %s",pt->idVoiture,pt->nomVoiture,pt->couleur,pt->marq,pt->nbplaces,pt->prixparJour,pt->EnLocation);
	}
	fclose(F);
	printf("\n\n");
	printf("**************votre operation a reUssi*************");
	}else
	{
		printf("*****************Operation a Annler*************");
	}
	printf("\n\n\n\n***********************apres supprimer*********************************\n\n");
	listevoiture(F);
	}
	
	
	
	
            
	            					               //pour calculer le nomber de linge dans le client et voiture.	



int nblign(FILE *F,const char *name){
	F=fopen(name,"r");
	char c; 
	int i=0;
	c=fgetc(F);
	while(c!=EOF){
		if(c=='\n') i++;             
		
	 
	 	c=fgetc(F);
	}
	return i;
}





                                                 /**   ************Modifier info d'un  voiture************   **/	



void modifiervoiture(FILE*F){
	int idvoiture,nbl,k,i;
	char reponse;
	
	nbl=nblign(F,"voiture.txt");
	F = fopen("voiture.txt","r");
	voiture *tab,*pt;
	tab=(voiture*)malloc(nbl*sizeof(voiture));
	printf("\n\n   ****!!!!!!!!!vous veuillez vraiment faire c'est operation O/N:");
	scanf("%c",&reponse);
	if(reponse=='o' || reponse=='O'){
	listevoiture(F);	
	printf("\n\n************************Avant Modifier*********************************\n");
	for(pt=tab;pt<tab+nbl;pt++){
	fscanf(F,"%d %s %s %s %d %d %s",&pt->idVoiture,&pt->nomVoiture,&pt->couleur,&pt->marq,&pt->nbplaces,&pt->prixparJour,&pt->EnLocation);
	}
	fclose(F);
	printf("  \n \nveuillez entrer le id a modifier : ");
	scanf("%d",&idvoiture);
	
    F=fopen("voiture.txt","w");
    for(pt=tab;pt<tab+nbl;pt++){
    	if(pt->idVoiture==idvoiture){
	printf("                  ->id de voiture....................:");
    scanf("%d",&pt->idVoiture);
    fflush(stdin);
    printf("                  ->le nom de voiture................:");
    scanf("%s",&pt->nomVoiture);
    fflush(stdin);
    printf("                  ->colour de voiture................:");
    scanf("%s",&pt->couleur);
    fflush(stdin);
    printf("                  ->la marque  de voiture............:");
    scanf("%s",&pt->marq);
	fflush(stdin);
    printf("                  ->Nomber de place..................:");
    scanf("%d",&pt->nbplaces);
    fflush(stdin);
    printf("                  ->prix par jour de voiture.........:");
    scanf("%d",&pt->prixparJour);
    fflush(stdin);
    printf("                  ->Enlocation Oui/No................:");
    scanf("%s",&pt->EnLocation);
    fflush(stdin);
  	fprintf(F,"\n%d       %s       %s       %s       %d       %d       %s",pt->idVoiture,pt->nomVoiture,pt->couleur,pt->marq,pt->nbplaces,pt->prixparJour,pt->EnLocation);
    printf("                        **************votre operation a reUssi**************");	
		}	else {
	fprintf(F,"\n%d       %s       %s       %s       %d       %d       %s",pt->idVoiture,pt->nomVoiture,pt->couleur,pt->marq,pt->nbplaces,pt->prixparJour,pt->EnLocation);
		}   
	} fclose(F);
	}else
	{
		printf("                    *****************!!!!!!!!!!!  Operation a Annler.");
	}
	printf("\n\n************************Apres Modifier*********************************\n\n\n");
	listevoiture(F);	
	}
	
	


	
								//**********prototype des  fonctions du Gestion des voitures*********|
  											
											  	 void  listeclient(FILE *F);
											  	 
 												 void  ajouteclient(FILE *F);	
 												 
                                                 void  supprimerclient(FILE*F);
                                                 
                                                 void  modifierclient(FILE*F);

	
	
	
	
	
	                                /**   ************Liste des clients************   **/                                                  
	
	
	void listeclient(FILE *F){
	printf("\n\n");
	char ch;
 	F=fopen("Client.txt","r");
 	ch=fgetc(F);
 	printf("  id       |Nom        |prenom        |CIN        |adresse     |Adresse    |telephone \n");
     while(ch!=EOF)	{
	 	printf("%c",ch);
 		ch=fgetc(F);
		 
		 }
	}
	
	
	
	
	                                /**   ***********Ajouter client*************   **/ 
	                                
	                                
	  void ajouterclient(FILE *F){
  	int i,n,k;
  	printf("\n\n");
  	listeclient(F);
	printf("\n************************Avant Ajouter*********************************\n\n");
  	printf("              ********ajouter de Client********");
  	 F=fopen("client.txt","a");
	cliente *tabclient,*pclient;
    printf("\n\n");
    printf("              le nombre des Client :");
    scanf("%d",&n);
    fflush(stdin);
    tabclient=(cliente*)malloc(n*sizeof(cliente));
    printf("\n\n");
    for(pclient=tabclient;pclient<tabclient+n;pclient++){
    printf("                  ******la client %d******",pclient-tabclient+1);
    printf("\n\n");
    printf("                  ->id de client....................:");
    scanf("%d",&pclient->idClient);
    
    printf("                  ->le nom de client................:");
    scanf("%s",&pclient->nom);
    fflush(stdin);
    printf("                  ->prenom de client................:");
    scanf("%s",&pclient->prenom);
    fflush(stdin);
    printf("                  ->CIN  de client..................:");
    scanf("%s",&pclient->cin);
	fflush(stdin);
    printf("                  ->Adresse de client...............:");
    scanf("%s",&pclient->adresse);
    fflush(stdin);
    printf("                  ->telephone de client.............:");
    scanf("%d",&pclient->phone);
    fflush(stdin);

    fprintf(F,"\n%d       %s       %s       %s       %s       %d",pclient->idClient,pclient->nom,pclient->prenom,pclient->cin,pclient->adresse,pclient->phone);
   printf("\n\n");
   }
   fclose(F);
	printf("\n************************Apres Ajouter*********************************\n");
    listeclient(F);
  }                                
	                                
	                                
                                                         /**   ************Supprimer un client************   **/
                                                         
                                                         

  void supprimerclient(FILE*F){
	int idclient,nbl,i;
	char reponse;
	nbl=nblign(F,"client.txt");
	F = fopen("client.txt","r");
	cliente *tab,*pt;
	tab=(cliente*)malloc(nbl*sizeof(cliente));
	printf("****!!!!!!!!!vous veuillez vraiment faire c'est operation O/N:");
	scanf("%c",&reponse);
	if(reponse=='o' || reponse=='O'){
	listeclient(F);
	printf("\n************************Avant supprimer*********************************\n");
	for(pt=tab;pt<tab+nbl;pt++){
		fscanf(F,"%d %s %s %s %s %d",&pt->idClient,&pt->nom,&pt->prenom,&pt->cin,&pt->adresse,&pt->phone);
	}
	fclose(F);
	printf("\n\n");
	printf("veuillez entrer le id a supprimer : ");
	scanf("%d",&idclient);
	fflush(stdin);
	F=fopen("client.txt","w");
	for(pt=tab;pt<tab+nbl;pt++){
		if(pt->idClient==idclient){
			
		}
		else fprintf(F,"\n%d       %s       %s       %s       %s       %d",pt->idClient,pt->nom,pt->prenom,pt->cin,pt->adresse,pt->phone);
	}
	fclose(F);
	printf("\n\n");
	printf("**************votre operation a reUssi*************");
	}else
	{
		printf("*****************Operation a Annler*************");
	}
        printf("\n************************Apres Supprimer*********************************\n");	
		listeclient(F);
	}
	
	
	
	
	
	                                            /**   ************Modifier un client************   **/
	
	
	
	void modifierclient(FILE*F){
	int idclient,nbl,i;
	char reponse;
	nbl=nblign(F,"client.txt");
	F = fopen("client.txt","r");
	cliente *tab,*pt;
	tab=(cliente*)malloc(nbl*sizeof(cliente));
	printf("****!!!!!!!!!vous veuillez vraiment faire c'est operation O/N:");
	scanf("%c",&reponse);
	if(reponse=='o' || reponse=='O'){
	listeclient(F);
	printf("\n  ************************Avant Modifier*********************************\n");
	for(pt=tab;pt<tab+nbl;pt++){
	fscanf(F,"%d %s %s %s %s %d",&pt->idClient,&pt->nom,&pt->prenom,&pt->cin,&pt->adresse,&pt->phone);
	}
	fclose(F);
	printf("\n   veuillez entrer le id a modifier : ");
	scanf("%d",&idclient);
    F=fopen("client.txt","w");
    for(pt=tab;pt<tab+nbl;pt++){
    	if(pt->idClient==idclient){
    printf("                  ->id de client....................:");
    scanf("%d",&pt->idClient);
    fflush(stdin);
    printf("                  ->le nom de client................:");
    scanf("%s",&pt->nom);
    fflush(stdin);
    printf("                  ->prenom de client................:");
    scanf("%s",&pt->prenom);
    fflush(stdin);
    printf("                  ->CIN  de client..................:");
    scanf("%s",&pt->cin);
	fflush(stdin);
    printf("                  ->Adresse de client...............:");
    scanf("%s",&pt->adresse);
    fflush(stdin);
    printf("                  ->telephone de client.............:");
    scanf("%d",&pt->phone);
    fflush(stdin); 
    fprintf(F,"\n%d       %s       %s       %s       %s       %d",pt->idClient,pt->nom,pt->prenom,pt->cin,pt->adresse,pt->phone);
    printf("                        **************votre operation a reUssi**************");	
		}	else {
		fprintf(F,"\n%d       %s       %s       %s       %s       %d",pt->idClient,pt->nom,pt->prenom,pt->cin,pt->adresse,pt->phone);
		}   
	} fclose(F);
	}else
	{
		printf("                    *****************!!!!!!!!!!!  Operation a Annler.");
	}
	listeclient(F);
	printf("\n************************Apres Modifier*********************************\n");
	listeclient(F);
	}
	
	
	
	
	
	                            //**********prototype des  fonctions du Location d'une voiture*********|
	                            
	                        	
											void  visualisercontat(FILE *F);
											
											int   prix(int id);       // fonction qui return prix par jour d'un voiture .
												
											void  modifier_apres_location(int id);      // fonction qui changer le cas de voiture apres la location (Enlocation OUI/NO) .
												
 											void  louercontrat(FILE *F);	
 												
 										    int   lignecontrat(FILE *F);    //fonction qui calculer le nombre de ligne dans le fichier contrat et qui return c'est nombre
 												
                                            void modifier_apres_returner(int id);      // fonction qui changer le cas de voiture apres la returner  (Enlocation OUI/NO) .
                                                
											void  retourn_voiture(FILE *F);
                                                
											void  supprimer_contrat(FILE *F);
                                                
											void  modifier_contrat(FILE *F);
                                                     
                                                     
                                                     
                                    
                                                   	
													   
													   /**   ************visualiser contrat************   **/
	

void  visualisercontat(FILE *F){
	printf("\n\n");
	char ch;
 	F=fopen("contrat.txt","r");
 	ch=fgetc(F);
 	printf("  Numcontra|idVoiture |idClient |date debut|date fin |cout\n");
    while(ch!=EOF)	{
	printf("%c",ch);
 	ch=fgetc(F);
 }
}





 
                                        /*fonction  return le prix de voiture qui louer pour calculer le cout */
                                    
 
 int prix(int id){
	FILE *F;
	F=fopen("voiture.txt","r");
	voiture info;
	while(!feof(F)){
		fscanf(F,"%d %s %s %s %d %d %s",&info.idVoiture,&info.nomVoiture,&info.couleur,&info.marq,&info.nbplaces,&info.prixparJour,&info.EnLocation);
		if(id==info.idVoiture){
			return info.prixparJour;
		}
	}
}





                                          /*fonction pour modifier le cas de voiture après la location (Enlocation OUI/NO)  */
                                          
                                          
                                          
void modifier_apres_location(int id){
	FILE *F;
	int nbl=nblign(F,"voiture.txt");
	voiture *tab,*pt;
	tab=(voiture*)malloc(nbl*sizeof(voiture));
	F=fopen("voiture.txt","r");
		for(pt=tab;pt<tab+nbl;pt++){
		fscanf(F,"%d %s %s %s %d %d %s",&pt->idVoiture,&pt->nomVoiture,&pt->couleur,&pt->marq,&pt->nbplaces,&pt->prixparJour,&pt->EnLocation);
	}
	fclose(F);
	F=fopen("voiture.txt","w");
		for(pt=tab;pt<tab+nbl;pt++){
			if(id==pt->idVoiture){
				strcpy(pt->EnLocation,"OUI");
				fprintf(F,"\n%d       %s       %s       %s       %d       %d       %s",pt->idVoiture,pt->nomVoiture,pt->couleur,pt->marq,pt->nbplaces,pt->prixparJour,pt->EnLocation);
			}
		else if(id!=pt->idVoiture) {
		fprintf(F,"\n%d       %s       %s       %s       %d       %d       %s",pt->idVoiture,pt->nomVoiture,pt->couleur,pt->marq,pt->nbplaces,pt->prixparJour,pt->EnLocation);
	}
}
	fclose(F);
}






                                                            /**   ************louer contrat************   **/

void louervoiture(FILE *F){
	contrat info;
	int n,i,h,H,c,k,nbj,num,C,idclient;
	contrat *tab,*pt;
	F=fopen("contrat.txt","a");
	listevoiture(F);
	printf("\n");
   	visualisercontat(F);
	printf("\n********************** avant louer***************************\n");
	printf("\n\nVeuillez vous le nombre de voiture que vous souhite a louer...:");
	scanf("%d",&n);
	tab = (contrat*)malloc(n*sizeof(contrat));
for(pt=tab;pt<tab+n;pt++){
			 printf("\n                  ->num de contrat .............:",num);
			 scanf("%d",&num);
			pt->numContrat=num;
			 printf("                  ->id de client................:");
			scanf("%d",&pt->idClient);
			H=(pt->idClient);
			c=rechidclient(H);
				if(c==1){
					    printf("                  ->id de voiture...............:");
					 scanf("%d",&pt->idVoiture);
					h=pt->idVoiture;
					k=rechchar(h);
					if(k==1){
						printf("\n**************Veuillez Remplissez le contrat .**************\n");
							    printf("\n\n*******************Date de debut******************\n\n");
                                     printf("*Jour........:");
                                     scanf("%d",&pt->debut.jour);
                                     fflush(stdin);
                                     printf("*Mois........:");
                                     scanf("%d",&pt->debut.mois);
                                     fflush(stdin);
                                     printf("*Ans.........:");
                                     scanf("%d",&pt->debut.ans);
	                                 fflush(stdin);
							    printf("\n\n********************Date de fin******************\n\n");
                                     printf("*Jour........:");
    								 scanf("%d",&pt->fin.jour);
   							         fflush(stdin);
    								 printf("*Mois........:");
    								 scanf("%d",&pt->fin.mois);
    								 fflush(stdin);
    								 printf("*Ans.........:");
    								 scanf("%d",&pt->fin.ans);
								 	fflush(stdin);
						  			k=prix(h);
									nbj=((pt->fin.ans)*365+(pt->fin.mois)*30+(pt->fin.jour))-((pt->debut.ans)*365+(pt->debut.mois)*30+(pt->debut.jour));
							        C = k*nbj;
							 printf("                  ->int cout.............: %d DH \n",C);
							(pt->cout)=C;
							
							fprintf(F,"\n%d   %d   %d    %d %d %d    %d %d %d    %d",pt->numContrat,pt->idClient,pt->idVoiture,pt->debut.jour,pt->debut.mois,pt->debut.ans,pt->fin.jour,pt->fin.mois,pt->fin.ans,pt->cout);
							modifier_apres_location(h);
							}else if(k==0){
				                 printf("******** La voiture deja louer ou n'exist pas!! ************");
						}		
				}
				 else if(c==0){
							printf("!!!!!!!!!  vous ete pas Enregistrer dans client,il faut d'abord l'ajouter");
							sleep(3);
							main();
							}
				}
									fclose(F);
			  printf("\n********************** avant louer***************************\n");
			  visualisercontat(F);
			  printf("\n");
			  listevoiture(F);
	}
	
	
	
	
	
	                                                    /* *****calcule le nombre de ligne dans le contrat****** */
	
int lignecontrat(FILE *F){
      	char c;
	    int lign=0;
	    F=fopen("contrat.txt","r");
	    c= getc(F);
	    while(c!=EOF){
		if(c=='\n'){
			  lign++;
		}
		   c=getc(F);
	    }
	    fclose(F);
	     return lign;
}



	
	
                                          /*fonction pour modifier le cas de voiture après retourner le voiture(Enlocation OUI/NO)  */
                                          
                                          
                                          
void modifier_apres_returner(int id){
	FILE *F;
	int nbl=nblign(F,"voiture.txt");
	voiture *tab,*pt;
	tab=(voiture*)malloc(nbl*sizeof(voiture));
	F=fopen("voiture.txt","r");
		for(pt=tab;pt<tab+nbl;pt++){
		fscanf(F,"%d %s %s %s %d %d %s",&pt->idVoiture,&pt->nomVoiture,&pt->couleur,&pt->marq,&pt->nbplaces,&pt->prixparJour,&pt->EnLocation);
	}
	fclose(F);
	F=fopen("voiture.txt","w");
		for(pt=tab;pt<tab+nbl;pt++){
			if(id==pt->idVoiture){
				strcpy(pt->EnLocation,"NO");
				fprintf(F,"\n%d       %s       %s       %s       %d       %d       %s",pt->idVoiture,pt->nomVoiture,pt->couleur,pt->marq,pt->nbplaces,pt->prixparJour,pt->EnLocation);
			}
		else fprintf(F,"\n%d       %s       %s       %s       %d       %d       %s",pt->idVoiture,pt->nomVoiture,pt->couleur,pt->marq,pt->nbplaces,pt->prixparJour,pt->EnLocation);
	}
	fclose(F);
}	





	
		                                              /**   ************Retourner voiture************   **/



void retourn_voiture(FILE *F){
	int idv,nblc=lignecontrat(F);
    visualisercontat(F);
	printf("\n********************** avant RETOURNER***************************\n");
	printf("Veuillez entrer le id de voiture a retourner :  ");
	scanf("%d",&idv);	
	contrat *tab,*pt;
	F=fopen("contrat.txt","r");
	tab=(contrat*)malloc(nblc*sizeof(contrat));
		for(pt=tab;pt<tab+nblc;pt++){
		fscanf(F,"%d %d %d %d %d %d %d %d %d %d ",&pt->numContrat,&pt->idClient,&pt->idVoiture,&pt->debut.jour,&pt->debut.mois,&pt->debut.ans,&pt->fin.jour,&pt->fin.mois,&pt->fin.ans,&pt->cout);
		}
		fclose(F);
	F=fopen("contrat.txt","w");
		for(pt=tab;pt<tab+nblc;pt++){
			if(idv==pt->idVoiture){
			modifier_apres_returner(idv);
			}
		else fprintf(F,"\n%d   %d   %d    %d %d %d    %d %d %d    %d",pt->numContrat,pt->idClient,pt->idVoiture,pt->debut.jour,pt->debut.mois,pt->debut.ans,pt->fin.jour,pt->fin.mois,pt->fin.ans,pt->cout);
		}
		printf("\n******* votre opération est terminer******* ");
	fclose(F);
	free(tab);	
	printf("\n********************** Apres RETOURNER***************************\n");
	visualisercontat(F);
}




                                                    /**   ************SUPPRIMER  contrat************   **/
 
 void supprimer_contrat(FILE *F){
	int numcont,idv;
	int nbl=lignecontrat(F);
	char reponse;
	visualisercontat(F);
	printf("\n********************** avant supprimer***************************\n");
	printf("Veuillez entrer le num de contrat a supprimer :  ");
	scanf("%d",&numcont);
	contrat *tab,*pt;
	tab=(contrat*)malloc(nbl*sizeof(contrat));
		F=fopen("contrat.txt","r");
			for(pt=tab;pt<tab+nbl;pt++){
	fscanf(F,"%d %d %d %d %d %d %d %d %d %d",&pt->numContrat,&pt->idClient,&pt->idVoiture,&pt->debut.jour,&pt->debut.mois,&pt->debut.ans,&pt->fin.jour,&pt->fin.mois,&pt->fin.ans,&pt->cout);
			}
			fclose(F);
		F=fopen("contrat.txt","w");
		for(pt=tab;pt<tab+nbl;pt++){
			if(numcont==pt->numContrat){
				
			}
		else fprintf(F,"\n%d   %d   %d    %d %d %d    %d %d %d    %d",pt->numContrat,pt->idClient,pt->idVoiture,pt->debut.jour,pt->debut.mois,pt->debut.ans,pt->fin.jour,pt->fin.mois,pt->fin.ans,pt->cout);
			}
			modifier_apres_returner(idv);
			printf("\n********contract a ete supprimer *******");
			fclose(F);
		printf("\n********************** Apres supprimer***************************\n");
	visualisercontat(F);
}        






                                                           /**   ************MODIFIER contrat************   **/



void modifier_contrat(FILE *F){
	int numcont,h,k,nbj,C;
	int nbl=lignecontrat(F);
	char reponse;
	visualisercontat(F);
	printf("\n********************** avant modifier***************************\n");
	printf("Veuillez entrer le num de contrat a Modifier :  ");
	scanf("%d",&numcont);
	contrat *tab,*pt;
	tab=(contrat*)malloc(nbl*sizeof(contrat));
		F=fopen("contrat.txt","r");
			for(pt=tab;pt<tab+nbl;pt++){
	fscanf(F,"%d %d %d %d %d %d %d %d %d %d",&pt->numContrat,&pt->idClient,&pt->idVoiture,&pt->debut.jour,&pt->debut.mois,&pt->debut.ans,&pt->fin.jour,&pt->fin.mois,&pt->fin.ans,&pt->cout);
			}
			fclose(F);
		F=fopen("contrat.txt","w");
		for(pt=tab;pt<tab+nbl;pt++){
			if(numcont==pt->numContrat){
				    printf("\n**************Veuillez modifier le contrat .**************\n");
					printf("                  ->id de voiture...............:");
					scanf("%d",&pt->idVoiture);
					h=pt->idVoiture;
					k=rechchar(h);
					if(k==1){
							    printf("\n\n*******************Date de debut******************\n\n");
                                     printf("*Jour........:");
                                     scanf("%d",&pt->debut.jour);
                                     fflush(stdin);
                                     printf("*Mois........:");
                                     scanf("%d",&pt->debut.mois);
                                     fflush(stdin);
                                     printf("*Ans.........:");
                                     scanf("%d",&pt->debut.ans);
	                                 fflush(stdin);
							    printf("\n\n********************Date de fin******************\n\n");
                                     printf("*Jour........:");
    								 scanf("%d",&pt->fin.jour);
   							         fflush(stdin);
    								 printf("*Mois........:");
    								 scanf("%d",&pt->fin.mois);
    								 fflush(stdin);
    								 printf("*Ans.........:");
    								 scanf("%d",&pt->fin.ans);
								 	fflush(stdin);
						  			k=prix(h);
									nbj=((pt->fin.ans)*365+(pt->fin.mois)*30+(pt->fin.jour))-((pt->debut.ans)*365+(pt->debut.mois)*30+(pt->debut.jour));
							        C = k*nbj;
							 printf("                  ->int cout.............: %d DH \n",C);
							(pt->cout)=C;
							
							fprintf(F,"\n%d   %d   %d    %d %d %d    %d %d %d    %d",pt->numContrat,pt->idClient,pt->idVoiture,pt->debut.jour,pt->debut.mois,pt->debut.ans,pt->fin.jour,pt->fin.mois,pt->fin.ans,pt->cout);
							modifier_apres_location(h);
							}else if(k==0){
				                 printf("******** La voiture deja louer ou n'exist pas!! ************");
				                 break;
						}		
				
			}
		else fprintf(F,"\n%d   %d   %d    %d %d %d    %d %d %d    %d",pt->numContrat,pt->idClient,pt->idVoiture,pt->debut.jour,pt->debut.mois,pt->debut.ans,pt->fin.jour,pt->fin.mois,pt->fin.ans,pt->cout);
			}
			printf("\n********contract a ete Modifier *******");
			fclose(F);
			printf("\n********************** Apres Modifier***************************\n");
	visualisercontat(F);
}





 main (){
    FILE *F;
      int choix;
      char reponse,idrech;

do{
	system("cls");
    printf("\n                                 \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                 \xb3 Menu Principal  \xb3");
	printf("\n                                 \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n                       \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n                       \xba                                              \xba");
    printf("\n                       \xba    Location..............................1   \xba");
    printf("\n                       \xba    Gestion voitures......................2   \xba");
    printf("\n                       \xba    Gestion clients.......................3   \xba");
    printf("\n                       \xba    Quitter...............................4   \xba");
    printf("\n                       \xba                                              \xba");
    printf("\n                       \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                   entre Votre choix :");
    scanf("%d",&choix);
    
if(choix==1)	{
	system("cls");
	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Location d'une voiture\xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	
	printf("\n\n");
	
	printf("\n                       \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n                       \xba                                              \xba");
	printf("\n                       \xba    Visualiser contrat...................1    \xba");
	printf("\n                       \xba    Louer voiture........................2    \xba");
	printf("\n                       \xba    Retourner voiture....................3    \xba");
	printf("\n                       \xba    Modifier contrat.....................4    \xba");
	printf("\n                       \xba    Supprimer contrat....................5    \xba");
	printf("\n                       \xba    Retour...............................6    \xba");
	printf("\n                       \xba                                              \xba");
	printf("\n                       \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
   
    do{
	printf("\n                                     entre voter choix :");
	scanf("%d",&choix);
	fflush(stdin);
	}while(choix<1 || choix>6);
	switch(choix){
	case 1:system("cls"); visualisercontat(F);
	break;
	case 2:system("cls"); louervoiture(F);
	break;
	case 3:system("cls"); retourn_voiture(F);
	break;
	case 4:system("cls"); modifier_contrat(F);
	break;
	case 5:system("cls"); supprimer_contrat(F);
	break;
	case 6:break;
	}
}
	

else    if(choix==2){
    system("cls");
	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Gestion des voitures \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	
	printf("\n\n");
	
	printf("\n                       \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n                       \xba                                              \xba");
	printf("\n                       \xba    lise des voitures.....................1   \xba");
	printf("\n                       \xba    Ajouter voiture.......................2   \xba");
	printf("\n                       \xba    Modifier voiture......................3   \xba");
	printf("\n                       \xba    Supprimer voiture.....................4   \xba");
	printf("\n                       \xba    Retour................................5   \xba");
	printf("\n                       \xba                                              \xba");
	printf("\n                       \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	
	do{
    printf("\n                                     entre voter choix :");
	scanf("%d",&choix);
	fflush(stdin);
	}while(choix<1 || choix>5);
	switch(choix){
	case 1:system("cls"); listevoiture(F);
	break;
	case 2:system("cls"); ajoutevoiture(F);
	break;
	case 3:system("cls"); modifiervoiture(F);
	break;
	case 4:system("cls"); supprimervoiture(F); 
	break;
	case 5:break;
	}
} 
else if(choix==3){
	system("cls");
	printf("\n                                  \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                  \xb3 Gestion des clients \xb3");
	printf("\n                                  \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	
	printf("\n\n");
	
	printf("\n                      \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n                      \xba                                              \xba");
	printf("\n                      \xba    lise des clients......................1   \xba");
	printf("\n                      \xba    Ajouter client........................2   \xba");
	printf("\n                      \xba    Modifier client.......................3   \xba");
	printf("\n                      \xba    Supprimer client......................4   \xba");
	printf("\n                      \xba    Retour................................5   \xba");
	printf("\n                      \xba                                              \xba");
	printf("\n                      \xba                                              \xba");
	printf("\n                      \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    do{
	printf("\n                                    entre voter choix :");
	scanf("%d",&choix);
	fflush(stdin);
	}while(choix<1 || choix>5);
	switch(choix){
	case 1:system("cls"); listeclient(F);
	break;
	case 2:system("cls"); ajouterclient(F);
	break;
	case 3:system("cls"); modifierclient(F);
	break;
	case 4:system("cls"); supprimerclient(F);
	break;
	case 5:break;
	}
}
else if(choix==4)exit(0);
else {
	printf("\n    votre domande n'exist pas !!!!!!");
}
printf("\n\n\n\n")	;
	printf("\n                                   voulez-vous continuez O/N :");
	scanf("%s",&reponse);
	fflush(stdin);
}while(reponse=='o' || reponse=='O');
	
  }
