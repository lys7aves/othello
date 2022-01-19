
void REMEMBER(node1 p, int k, int z)
{
	int x, y;
	x = k/10;
	y = k%10;
	put_.board[x][y] += z;
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(p.board[x+i][y+j]==-1){
				for(int l=2;l<=7;l++){
					if(p.board[x+l*i][y+l*j]==0) break;
					if(p.board[x+l*i][y+l*j]==1){
						for(int k=1;k<l;k++){
							eat_.board[x+k*i][y+k*j] += z;
						}
						break;
					}
				}
			}
		}
	}
}

void ANALYSIS(int z)
{
	sprintf(file_name, "%s\\%s brain.txt", file_position, name);
	FILE *out;
	out = fopen(file_name,"w");
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			fprintf(out, "%d	", put.board[i][j] + z*put_.board[i][j]);
		}
		fprintf(out, "\n");
	}
	fprintf(out, "\n");
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			fprintf(out, "%d	", eat.board[i][j] + z*eat_.board[i][j]);
		}
		fprintf(out, "\n");
	}
	fprintf(out, "\n");
	fprintf(out, "%d %d %d\n", win, lose, draw);
	fclose(out);
	
	sprintf(file_name, "%s\\%s process.txt", file_position, name);
	FILE *out2;
	out2 = fopen(file_name,"aw");
	fprintf(out2, "#%d\n", win+lose+draw);
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			fprintf(out2, "%d	", put.board[i][j] + z*put_.board[i][j]);
		}
		fprintf(out2, "\n");
	}
	fprintf(out2, "\n");
	for(int i=1;i<=size;i++){
		for(int j=1;j<=size;j++){
			fprintf(out2, "%d	", eat.board[i][j] + z*eat_.board[i][j]);
		}
		fprintf(out2, "\n");
	}
	fprintf(out2, "\n");
	fprintf(out2, "%d %d %d\n", win, lose, draw);
	fprintf(out2, "\n");
	fclose(out2);
}
