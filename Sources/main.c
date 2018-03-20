/**
 * TEAUDORS Mickaël
 * This program has two main purposes.
 * The first is to decrypt a given text assuming that you have the key and you know the algorithm used to encrypt the text.
 * The second is to encrypt a text choosing the algoritm and the key.
 * The algorithms supported by this program : substitution, caesar, Vigenère, self-encryption, playfair
 */

#include <stdio.h>
#include <stdlib.h>
#include "../Headers/error.h"
#include "../Headers/utilCipher.h"
#include "../Headers/enum.h"
#include "../Headers/structures.h"
#include "../Headers/utilEnum.h"


/**
 * args[1] : choose between encryption and decryption
            * -e : encrypt
            * -d : decrypt
 * args[2] : choose the algorithm
            * -s : substitution
            * -c : cesar
            * -v : vigenere
            * -se : self-encryption
            * -p : playfair
 * args[3] : name of the file containing the original text, either the encrypted text if we want to decrypt or the original text if we want to encrypt.
 * args[4] : the key, either a figure (cesar), a word (vigenere) or the name of a file containing the substitution (substitution).
 * args[5] : (OPTIONAL) name of the file to display the result. If not specified, the result will be displayed on the console.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc , char *args[]) {

    /* ******************************** Check the arguments ********************************/

    if(argc < 5 || argc > 6)
        error("Arguments are not corrects ! Please read the documentation before launching the programm");

    // get all the information provided by the user in a structure
    struct InfoCipher infoCipher = initInfoCipherFromArgs(args);


    char *stringMode = stringFromMode(infoCipher.mode);
    char *stringAlgo = stringFromAlgo(infoCipher.algo);

    printf("MODE : %s\n" , stringMode);
    printf("ALGO : %s\n" , stringAlgo);
    printf("ORIGINAL FILE : %s\n" , infoCipher.originalFileName);
    printf("KEY : %s\n" , infoCipher.key);

    free(stringMode);
    free(stringAlgo);


    exit(EXIT_SUCCESS);
}