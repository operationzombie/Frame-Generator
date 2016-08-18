#include <stdio.h>
#include <string.h>		//String length
#include <stdlib.h>		

#define START_DELIMITER 0x7E	
#define FRAME_ID 0x01			/*Response requested */
#define ADDR_16 0xFFFE      /*Address transmissmison(unknown or broadcast 16 bits) */
#define BROADCAST_RDS 0x00	/*Max hops*/
#define OPT 0x00				/* NO OPTIONS */
#define NUM_NODES 0x10 	/* max number of nodes in the system */


struct{
	char *node_id;
	int addr;
	int type;		/* 0 Coordinater, 1 Router */ 
}typedef node_addr


node_addr addr_book[NUM_NODES];


int main(){


	return 0;
}

/*Function for finding address */
int findAddress(char *node_name){
	int i = 0;

	for(i = 0; i < NUM_NODES; i++){
		if(node_name == addr_book[i].node_id){
			return addr_book[i].addr;
		}
	}

	return -1;
}

/* Function for filling the address table for each nodes*/
void fillTable(){
	/*Aurora identifier */
	addr_book[0].node_id = "aurora";
	addr_book[0].addr = 0x40E70F9E;
	addr_book[0].type = 0;

	/*Belle identifier */
	addr_book[1].node_id = "belle";
	addr_book[1].addr = 0x40E70F96;
	addr_book[1].type = 1;

	/*Ariel identifier */
	addr_book[2].node_id = "ariel";
	addr_book[2].addr = 0x40D56910;
	addr_book[2].type = 1;
}

char *generateFrame(char *name, char *data){
	int dataLen = 14 + strlen(data);		//Data length

	char frame [dataLen];

	frame[0] = START_DELIMITER;
	//frame[1]			/*

}