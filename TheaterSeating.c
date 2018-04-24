#include <stdio.h>

void displaySeats(char *seats);

void displaySeats(char *seats) {
	printf("\t\tSeats\n");
	printf("\t123456789012345687901234567890\n");

	for (int rowNum = 0; rowNum < 15; rowNum++) {
		printf("Row %d\t", rowNum + 1);
		for (int seatNum = 0; seatNum < 30; seatNum++) {
			printf("%c", *((seats + rowNum * 30) + seatNum));
		}
		printf("\n");
	}
}

int main() {
	double priceOfRow[15];
	double totalTicketSales = 0;
	int seatsSold = 0;

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

	displaySeats((char *) seats); // Displays seats

	int row, seat;

	do {
		printf("Please enter the row that you want (1-15): ");
		fflush(stdout);
		scanf("%d", &row);
	} while (row < 1 || row > 15);

	do {
		printf("Please enter the seat that you want in row %d (1-30): ", row);
		fflush(stdout);
		scanf("%d", &seat);
	} while (seat < 1 || seat > 30);

	if (seats[row - 1][seat - 1] == '*') {
		seats[row - 1][seat - 1] = '#';
		totalTicketSales += priceOfRow[row - 1];
		seatsSold++;
	} else {
		printf("Row #%d, Seat #%d is taken.\n\n", row, seat);
	}
	
	displaySeats((char *) seats); // Displays updated seats
	
	int choice = 0;

	do {
		printf("Additional Options\n");
		printf("-------------------------\n");
		printf("(1) View total number of ticket sales\n");
		printf("(2) View number of seats sold\n");
		printf("(3) View available seats in a row\n");
		printf("(4) View total number of available seats in the auditorium\n");
		printf("(5) Exit program\n-->");
		fflush(stdout);
		scanf("%d", &choice);
	} while (choice < 1 || choice > 4);
	
	
	int rowNumber;
	int numOfSeatsInRow = 0;

	switch (choice) {
	case 1:
		printf("The total number of all ticket sales is: $%.2lf",
				totalTicketSales);
		break;
	case 2:
		printf("The number of seats sold is: %d", seatsSold);
		break;
	case 3:
		do {
			printf("Please enter the row that you want to check (1-15): ");
			fflush(stdout);
			scanf("%d", &rowNumber);
		} while (rowNumber < 1 || rowNumber > 15);

		for (int seatNumber = 0; seatNumber < 30; seatNumber++) {
			if (seats[row - 1][seatNumber] == '*') {
				numOfSeatsInRow++;
			}
		}
		printf("The number of seats available in row %d is: %d", rowNumber,
				numOfSeatsInRow);
		break;
	case 4:
		printf("The total number of seats available in the auditorium is: %d",
				30 - seatsSold);
		break;

		return 0;
	}
}
