#include <stdio.h>

void displaySeats(char *seats);

void displaySeats(char *seats) {
	printf("\t\tSeats\n");
	printf("\t123456789012345687901234567890\n");

	for (int rowNum = 0; rowNum < 15; rowNum++) {
		printf("Row %d\t", rowNum + 1);
		for (int seatNum =  0; seatNum < 30; seatNum++) {
			printf("%c", *((seats + rowNum * 30) + seatNum));
		}
		printf("\n");
	}
}

int main() {
	double priceOfRow[15];
	double totalTicketSales = 0;
	int seatsSold = 0;

	int flag = 0; //0 for false, 1 for true

	for (int row = 0; row < 15; row++) {
		printf("Please enter the price of row %d: ", row + 1);
		fflush(stdout);
		scanf("%lf", &priceOfRow[row]);
	}

	char seats[15][30];

	// Initializes all seats to be available.
	for (int rowNum = 0; rowNum < 15; rowNum++) {
		for (int seatNum = 0; seatNum < 30; seatNum++) {
			seats[rowNum][seatNum] = '*';
		}
	}

	while (flag == 0) {
		displaySeats((char *)seats);
		int row, seat;

		do {
		printf("Please enter the row that you want (1-15): ");
		fflush(stdout);
		scanf("%d", &row);
		} while (row < 1 || row > 15);

		do {
		printf("Please enter the seat that you want in row %d (1-15): ", row);
		fflush(stdout);
		scanf("%d", &seat);
		} while (seat < 1 || seat > 30);

		if (seats[row][seat] == '*') {
			seats[row][seat] = '#';
			totalTicketSales += priceOfRow[row];
			seatsSold++;
		}
		else {
			printf("Row #%d, Seat #%d is taken.\n", row, seat);
		}

		int choice = 0;
		do {
		printf("Additional Options\n");
		printf("-------------------------");
		printf("(1) View total number of ticket sales\n");
		printf("(2) View number of seats sold\n");
		printf("(3) View available seats in a row\n");
		printf("(4) View total number of available seats\n");
		fflush(stdout);
		scanf("%c", &choice);
		} while (choice < 1 || choice > 4);

		switch(choice) {
		case 1:
			printf("The total number of all ticket sales is: %.2lf", totalTicketSales);
			break;
		case 2:
			printf("The number of seats sold is: %d", seatsSold);
			break;
		case 3:
			printf("The number of seats available in each row are: %d", seatsSold);
			break;
		case 4:
			printf("The total number of seats available in the auditorium is:", 30 - seatsSold);
			break;



	}




	return 0;
}
