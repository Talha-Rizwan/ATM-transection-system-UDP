# ATM-transection-system-UDP

ATM: An automated teller machine (ATM) or cashpoint is an electronic telecommunications
device that enables customers of financial institutions to perform financial transactions, such as
cash withdrawals, deposits, funds transfers, or account information inquiries, at any time and
without the need for direct interaction with bank staff.
The main steps involved in an ATM are:
● Card Reading
● Pin Verification
● Cash Withdraw
These steps are performed in the given sequence. i implemented this system using the client-server architecture.

I have created one server and one client. The client program has to run 3 times in order for the server to proceed. 
In the start of the program, the server waits for all the three clients to bind with it
the server displays the menu and give options to the user. Then it randomly assigns the clients numbers from 1-3 and if the number is equal to zero then the server shows the error message and terminates the program. If its not zero then the server assigns different tasks to the clients in a sequential order according to the randomly given number. 
The client with id equal to 1 performs the first task i-e the card reading process. It sends back the confirmation message to the server that the card reading was successful.
The  client with id equal to 2 performs the second task i-e the pin verification process. It asks the user the pin of account and sends back the confirmation message to the server that the pin was correct.
The client with id equal to 3 performs the last task i-e the cash withdrawl process. It asks the usere to enter the amount he wants to withdraw and deducts the amount form the total amount from his account and sends back the  message to the server that the  server can end the transection.

When one client is working, the other two clients wait for its completion before they start their task.
