def main():
    num1 = get_int("Diga um número: ");
    num2 = get_int("Diga outro número: ");
    for i in range(num1 + 1, num2):
         print(i, sep= " ")

def get_int(string):
        number = 0
        try:
            number = int(input(string))
        except:
            print("número inválido")
            get_int(string)
        return number

main()