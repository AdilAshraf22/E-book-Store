#include <stdio.h>
#include <string.h>

struct Ebook {
    char title[100];
    char author[100];
    float price;
    int stock;
};

void displayEbooks(struct Ebook ebooks[], int n) {
    printf("E-Books Catalog:\n");
    printf("-----------------------------------------------------\n");
    printf("Title\tAuthor\tPrice\tStock\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%s\t%.2f\t%d\n", ebooks[i].title, ebooks[i].author, ebooks[i].price, ebooks[i].stock);
    }
    printf("-----------------------------------------------------\n");
}

void purchaseBook(struct Ebook ebooks[], int index, int cart[], float *totalCost) {
    if (ebooks[index].stock > 0) {
        ebooks[index].stock--;
        printf("%s has been added to your cart.\n", ebooks[index].title);
        cart[index]++; 
        *totalCost += ebooks[index].price; 
    } else {
        printf("Sorry, %s is out of stock.\n", ebooks[index].title);
    }
}

int main() {
    struct Ebook ebooks[] = {
    {"1. To Kill a Mockingbird", "Harper Lee", 500, 30},
    {"2. 1984", "George Orwell", 450, 25},
    {"3. Pride and Prejudice", "Jane Austen", 550, 20},
    {"4. The Great Gatsby", "F. Scott Fitzgerald", 480, 15},
    {"5. One Hundred Years of Solitude", "Gabriel Garcia Marquez", 600, 18},
    {"6. The Catcher in the Rye", "J.D. Salinger", 520, 22},
    {"7. The Hobbit", "J.R.R. Tolkien", 580, 28},
    {"8. To the Lighthouse", "Virginia Woolf", 510, 12},
    {"9. Brave New World", "Aldous Huxley", 470, 17},
    {"10. The Lord of the Rings", "J.R.R. Tolkien", 700, 25},
    {"11. The Chronicles of Narnia", "C.S. Lewis", 550, 20},
    {"12. Moby-Dick", "Herman Melville", 1000, 15},
    {"13. Crime and Punishment", "Fyodor Dostoevsky", 600, 18},
    {"14. Jane Eyre", "Charlotte Bronte", 520, 22},
    {"15. The Odyssey", "Homer", 580, 28},
    {"16. The Picture of Dorian Gray", "Oscar Wilde", 510, 12},
    {"17. War and Peace", "Leo Tolstoy", 700, 25},
    {"18. Frankenstein", "Mary Shelley", 470, 17},
    {"19. The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 520, 22},
    {"20. Wuthering Heights", "Emily Bronte", 550, 20},
    {"21. Anna Karenina", "Leo Tolstoy", 600, 18},
    {"22. The Alchemist", "Paulo Coelho", 480, 15},
    {"23. The Road", "Cormac McCarthy", 510, 12},
    {"24. The Grapes of Wrath", "John Steinbeck", 580, 28},
    {"25. The Sun Also Rises", "Ernest Hemingway", 470, 17},
    {"26. The Brothers Karamazov", "Fyodor Dostoevsky", 700, 25},
    {"27. Sense and Sensibility", "Jane Austen", 520, 22},
    {"28. Siddhartha", "Hermann Hesse", 550, 20},
    {"29. Gone with the Wind", "Margaret Mitchell", 600, 18},
    {"30. The Count of Monte Cristo", "Alexandre Dumas", 480, 15},
    {"31. Dracula", "Bram Stoker", 580, 28},
    {"32. The Scarlet Letter", "Nathaniel Hawthorne", 510, 12},
    {"33. A Tale of Two Cities", "Charles Dickens", 470, 17},
    {"34. The Shining", "Stephen King", 700, 25},
    {"35. The Hound of the Baskervilles", "Arthur Conan Doyle", 520, 22},
    {"36. The Jungle Book", "Rudyard Kipling", 550, 20},
    {"37. The Color Purple", "Alice Walker", 600, 18},
    {"38. The Iliad", "Homer", 480, 15},
    {"39. Great Expectations", "Charles Dickens", 510, 12},
    {"40. Les Miserables", "Victor Hugo", 580, 28},
    {"41. The Wind in the Willows", "Kenneth Grahame", 470, 17},
    {"42. The Girl with the Dragon Tattoo", "Stieg Larsson", 700, 25},
    {"43. The Importance of Being Earnest", "Oscar Wilde", 520, 22},
    {"44. The Silmarillion", "J.R.R. Tolkien", 550, 20},
    {"45. The Fountainhead", "Ayn Rand", 600, 18},
    {"46. A Clockwork Orange", "Anthony Burgess", 480, 15},
    {"47. The War of the Worlds", "H.G. Wells", 510, 12},
    {"48. The Secret Garden", "Frances Hodgson Burnett", 580, 28},
    {"49. The Handmaid's Tale", "Margaret Atwood", 470, 17},
    {"50. Life of Pi", "Yann Martel", 700, 25}
};
    
    int numEbooks = sizeof(ebooks) / sizeof(ebooks[0]);
    int choice;
    float totalCost = 0;
    int cart[100] = {0}; 

    printf("Welcome to the E-Book Store!\n");

    do {
        printf("1. Browse E-Books\n");
        printf("2. Add to Cart\n");
        printf("3. View Cart\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayEbooks(ebooks, numEbooks);
                break;
            case 2:
                int ebookIndex;
                printf("Enter the e-book index (1-%d) to add to the cart: ", numEbooks);
                scanf("%d", &ebookIndex);
                if (ebookIndex >= 1 && ebookIndex <= numEbooks) {
                    ebookIndex--; 
                    purchaseBook(ebooks, ebookIndex, cart, &totalCost);
                } else {
                    printf("Invalid e-book index.\n");
                }
                break;
            case 3:
                printf("Your Cart:\n");
                printf("-----------------------------------------------------\n");
                printf("Title\tQty\tPrice\n");
                for (int i = 0; i < numEbooks; i++) {
                    if (cart[i] > 0) {
                        printf("%s\t%d\t%.2f\n", ebooks[i].title, cart[i], cart[i] * ebooks[i].price);
                    }
                }
                printf("-----------------------------------------------------\n");
                printf("Total Cost: %.2f\n", totalCost);
                break;
            case 4:
                printf("Thank you for your purchase!\n");
                totalCost = 0;
                memset(cart, 0, sizeof(cart)); 
                break;
            case 5:
                printf("Thank you for visiting our E-Book Store!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        if (choice == 2 || choice == 4) {
            printf("Updated Stock:\n");
            displayEbooks(ebooks, numEbooks);
        }
    } while (choice != 5);

    return 0;
}
