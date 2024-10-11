class BankAccount:
    def __init__(self, name, account_number, initial_deposit):
        self.name = name
        self.account_number = account_number
        self.balance = initial_deposit

    def deposit(self, amount):
        if amount <= 0:
            print("Deposit amount must be greater than 0.")
            return
        self.balance += amount
        print(f"Deposited R{amount:.2f}. New balance is R{self.balance:.2f}.")

    def withdraw(self, amount):
        if amount <= 0:
            print("Withdrawal amount must be greater than 0.")
            return
        if amount > self.balance:
            print("Insufficient funds for this withdrawal.")
            return
        self.balance -= amount
        print(f"Withdrew R{amount:.2f}. New balance is R{self.balance:.2f}.")

    def check_balance(self):
        print(f"Current balance: R{self.balance:.2f}")

    def display_account_details(self):
        print(f"--- Account Details ---")
        print(f"Account Holder: {self.name}")
        print(f"Account Number: {self.account_number}")
        print(f"Current Balance: R{self.balance:.2f}")


def create_account():
    name = input("Enter your name: ")
    account_number = input("Enter your account number: ")
    initial_deposit = float(input("Enter your initial deposit (must be greater than 0): "))
    while initial_deposit <= 0:
        initial_deposit = float(input("Invalid amount. Enter your initial deposit (must be greater than 0): "))
    return BankAccount(name, account_number, initial_deposit)


def main():
    print("--- Bank Account Management System ---")
    account = None

    while True:
        print("\n1. Create Account")
        print("2. Deposit Money")
        print("3. Withdraw Money")
        print("4. Check Balance")
        print("5. Display Account Details")
        print("6. Exit")
        choice = input("Enter your choice (1-6): ")

        if choice == '1':
            account = create_account()
            print("Account created successfully!")

        elif choice == '2':
            if account:
                amount = float(input("Enter amount to deposit: "))
                account.deposit(amount)
            else:
                print("No account found. Please create an account first.")

        elif choice == '3':
            if account:
                amount = float(input("Enter amount to withdraw: "))
                account.withdraw(amount)
            else:
                print("No account found. Please create an account first.")

        elif choice == '4':
            if account:
                account.check_balance()
            else:
                print("No account found. Please create an account first.")

        elif choice == '5':
            if account:
                account.display_account_details()
            else:
                print("No account found. Please create an account first.")

        elif choice == '6':
            print("Exiting the system. Goodbye!")
            break

        else:
            print("Invalid choice. Please select a valid option.")


if __name__ == "__main__":
    main()
