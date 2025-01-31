#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

unsigned long load_balance();
void save_balance(unsigned long amount);

int main() {
    int pin[] = {2001, 2113, 3128, 2663, 3382};  
    char input[50];
    int pincode; 
    int choice;
    unsigned long amount = load_balance();
    unsigned long withdrawal, acc_number;
    int break_pin = 0; 
    int card_choice;
    int thousand=200, five_thousand=100, five_hundred=250; 
    int cash_thousand=0, cash_fthousand=0, cash_hundred=0;
    int amount_choice, deposit, transfer;
    int valid_input;
    
    FILE *file; 
    file = fopen("transaction_history.txt", "a");
    if (file == NULL) {
        printf("Error opening transaction history file.\n");
        return 1;
    }
    while (card_choice != 1) {
        printf("Please Enter Your card (press 1 to continue)\n"); //press 1 to continue
        scanf("%d", &card_choice);
    }

     while (break_pin != 1) {
        printf("Enter your PIN code: ");
        pincode = 0;  
        int digit_count = 0;
        char ch;

        while (break_pin != 1) {  
            ch = getch();  
            if (ch == 13) { //Enter  
                break;
            } else if ((ch == '\b' || ch == 127) && digit_count > 0) { //Backspace  
                 pincode /= 10;  
                 printf("\b \b");  
                 digit_count--;
            } else if (ch >= '0' && ch <= '9' && digit_count < 4) {  
                pincode = pincode * 10 + (ch - '0');  
                printf("*"); 
                digit_count++;
            }
        }
        printf("\n");  
       

        for (int i = 0; i < 5; i++) {
            if (pincode == pin[i]) {
                break_pin = 1;  
            }
        }

        if (break_pin != 1) {
            printf("Incorrect PIN code!\n");
        }
    }

    printf("PIN validated successfully!\n");
    do {
        printf("\nHello, welcome to our ATM service\n");
        printf("1. Balance Checking\n");
        printf("2. Cash withdrawal\n");
        printf("3. Cash deposition\n");
        printf("4. Transfer money\n");
        printf("5. Exit\n");
        printf("\nPlease proceed with your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nThe account balance is: Rs %lu\n", amount);
                fprintf(file, "Balance checked: Rs %lu\n", amount);
                break;
          case 2:
    do
    {
        printf("\n\nSelect the amount to be withdrawn\n\n\n");
        printf("1. 500  \t");
        printf("2. 1000\n");
        printf("3. 2000 \t");
        printf("4. 5000\n");
        printf("5. 10000\t");
        printf("6 .25000\n");
        printf("7. 50000\t");
        printf("8. Input amounnt\n");
        printf("         9.Exit\n");

        printf("Enter Choice : ");
        scanf("%d",&amount_choice);

       switch (amount_choice)
       {
       case 1:
       if (five_hundred >= 1 )
       {
        if (amount >= 1000)
       {
       amount-=500;
       five_hundred--;
             printf("Please collect your cash\n");
        printf("Your remaining balance is: Rs %lu\n", amount);
        printf("you get 1 500 rs note");
        fprintf(file, "Cash withdrawn: Rs 500 | Remaining balance: Rs %lu\n", amount);
       }
       else {
        printf("Insufficient Balance\n");
       }
       }
       else{
        printf("ATM is out of cash\n");
       }
        break;
       case 2: if (five_hundred >= 2)
       {
       
        if (amount >= 1500)
       {
       
        amount-=1000;
        five_hundred -= 2;
        printf("Please collect your cash\n");
        printf("Your remaining balance is: Rs %lu\n", amount);
        printf("You get 2 500 rs Note");
        fprintf(file, "Cash withdrawn: Rs 1000 | Remaining balance: Rs %lu\n", amount);
       }
       else {
        printf("Insufficient Balance\n");
       }
       }
       else{
        printf("ATM is out of cash\n");
       }
        break;
        case 3: if (five_hundred >= 4){
        
         if (amount >= 2500)
        {
        
         amount -= 2000;
         five_hundred -= 4;
        
        printf("Please collect your cash\n");
        printf("Your remaining balance is: Rs %lu\n", amount);
        printf("You get 4 500 rs Note");
        fprintf(file, "Cash withdrawn: Rs 2000 | Remaining balance: Rs %lu\n", amount);
        }
        else {
            printf("Insufficient balance \n");
        }
        }
        else{
            printf("ATM is out of cash\n");
        }
        break;
        case 4:if (thousand >= 5)
        {
        
        if (amount >= 5500)
        {
    
         amount-= 5000;
         thousand -= 5;
        printf("Please collect your cash\n");
        printf("Your remaining balance is: Rs %lu\n", amount);
        printf("You get 5 1000 rs Note");
        fprintf(file, "Cash withdrawn: Rs 5000 | Remaining balance: Rs %lu\n", amount);
        }
        else{
            printf("Insuffiecient Balance \n");
        }
        }
        else{
            printf("ATM is out of cash\n");
        }
        break;
        case 5: if (thousand >= 10)
        {
         if (amount >= 10500)
        {
         amount -= 10000;
         thousand -= 10;
        printf("Please collect your cash\n");
        printf("Your remaining balance is: Rs %lu\n", amount);
        printf("You get 10  1000 rs Note");
        fprintf(file, "Cash withdrawn: Rs 10000 | Remaining balance: Rs %lu\n", amount);
        }
        else{
            printf("Insuffiecient balance\n");
        }
        }
          else{
            printf("ATM is out of cash\n");
        }
        break;
        case 6: if (five_thousand >= 5)
        {
        
        if (amount >= 25500)
        {
         amount -= 25000;
         five_thousand -= 5;
        printf("Please collect your cash\n");
        printf("Your remaining balance is: Rs %lu\n", amount);
        printf("You get 5 5000 rs Note");
        fprintf(file, "Cash withdrawn: Rs 25000 | Remaining balance: Rs %lu\n", amount);
        }
            else{
            printf("Insuffiecient balance\n");
        }
        }
        else {
            printf("ATM is out of cash\n");
        }
        break;
        case 7: if (five_thousand >= 10)
        {
        
        if (amount >= 50500)
        {
         amount -= 50000;
         five_thousand -= 10;
        printf("Please collect your cash\n");
        printf("Your remaining balance is: Rs %lu\n", amount);
        printf("You get 10 5000 rs Note");
        fprintf(file, "Cash withdrawn: Rs 50000 | Remaining balance: Rs %lu\n", amount);
        }
            else{
            printf("Insuffiecient balance\n");
        }
        }
          else{
            printf("ATM is out of cash\n");
        }
        break;
        case 8:  
    printf("\n Enter amount to be withdrawn : \n");    
    scanf("%lu", &withdrawal);

    if (withdrawal % 500 != 0) {
        printf("\nEnter only multiples of 500\n");
    } else if (withdrawal > (amount - 500)) {
        printf("\nYou have insufficient balance!\n");
    } else {
        if (withdrawal >= 500 && withdrawal <= 5000) {
            cash_hundred = withdrawal / 500;
            if (five_hundred >= cash_hundred) {
                printf("you recieved %d 500 rs Note\n",cash_hundred);
                five_hundred -= cash_hundred;
            } else {
                printf("ATM is out of cash!\n");
                break;
            }
        } else if (withdrawal > 5000 && withdrawal <= 15000) {
            cash_thousand = withdrawal / 1000;
            if (thousand >= cash_thousand) {
                 printf("you recieved %d 1000 rs Note\n",cash_thousand);
                thousand -= cash_thousand;
            } else {
                printf("ATM is out of cash!\n");
                break;
            }
        } else {
            cash_fthousand = withdrawal / 5000;
            if (five_thousand >= cash_fthousand) {
                printf("you recieved %d 5000 rs Note\n",cash_fthousand);
                five_thousand -= cash_fthousand;
            } else {
                printf("ATM is out of cash!\n");
                break;
            }
        }

        amount -= withdrawal;
        printf("Please collect your cash\n");
        printf("Your remaining balance is: Rs %lu\n", amount);
        fprintf(file, "Cash withdrawn: Rs %lu | Remaining balance: Rs %lu\n", withdrawal, amount);
    }

    break; 
    case 9: break;
       default: printf("select valid choice!");
        break;
       }
    } while (amount_choice != 9);
      break;
            case 3:
                printf("\nEnter the amount to deposit: ");
                scanf("%d", &deposit);
                if (deposit < 0)
                {
                    printf("Please Enter Positive Amount\n");
                }
                else if (deposit == 0)
                {
                    printf("Please enter some amount\n");
                }
                else if (deposit > 0)
                {
                amount += deposit;
                printf("Your new balance is: Rs %lu\n", amount);
                fprintf(file, "Cash deposited: Rs %lu | New balance: Rs %lu\n", deposit, amount);
                }
             break;
            case 4:
                printf("Enter account number you want to transfer your cash to (Account number must contain 7 digits !) : ");
                scanf("%lu",&acc_number);
                if (acc_number <= 999999 || acc_number > 9999999)
                {
                    printf("Account number must be 7 digits !\n");
                }
                else{
                printf("\nEnter amount to transfer: ");
                scanf("%d",&transfer);
                if (transfer <= 0)
                {
                    printf("Enter positive Numbers\n");
                }
                else {
                if (transfer % 500 != 0)
                {
                    printf("Enter only multiple of 500\n");
                }
                
                else if (transfer > (amount - 500))
                {
                    printf("Insufficient Balance !\n");
                }
                else{
                amount -= transfer;
                printf("Your new balance is: Rs %lu\n", amount);
                fprintf(file, "Cash transferred: Rs %d | New balance: Rs %lu\n", transfer, amount);
                }
                }
                }
                break;

            case 5: 
                printf("\nThank you for using ATM services.\n");
                   fprintf(file, "User exited the ATM.\n");
                break;
            default:
                printf("You've made an invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
        fclose(file);
        save_balance(amount);
    return 0;
}


unsigned long load_balance() {
    FILE *fptr = fopen("balance.txt", "r");
    unsigned long balance = 5000;  
    if (fptr != NULL) {
        fscanf(fptr, "%lu", &balance);
        fclose(fptr);
    }
    return balance;
}

void save_balance(unsigned long amount) {
    FILE *fptr = fopen("balance.txt", "w");
    if (fptr != NULL) {
        fprintf(fptr, "%lu", amount);
        fclose(fptr);
    } else {
        printf("Error saving balance to file.\n");
    }
}

