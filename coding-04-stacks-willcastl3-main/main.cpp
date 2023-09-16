/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    /*
     * At this point you have two parallel arrays. A simple integer array (ids)
     * that holds random integers, and 2D character array (which is a 
     * 1D array of strings) holding 'dummy' strings. Compile and run the
     * program as-is and you will see the display of these two arrays.
     */
    
    // declare the stack
    Stack stack;
    
    /*****************************************
     * Perform your stack tests starting here
     *****************************************/
    
    /* first call isEmpty(), peek(), and pop() to show what happens when
     * you do that on an empty stack */

    cout << "Beginning tests..." << endl << endl << "Testing empty operations." << endl;
    cout << "=====================================================" << endl;

    // testing isEmpty() on empty stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }
    cout << endl;

    Data userdata;
    // testing peek() and pop() on empty stack
    if(stack.peek(userdata)){
        cout << "peeked = success" << endl;
        cout << "ID: " << userdata.id << endl;
        cout << "Information: " << userdata.information << endl;
    } else{
        cout << "Peek underflow error: stack is empty" << endl;
        cout << "ID: " << userdata.id << endl;
        cout << "Information: " << userdata.information << endl;
    }

    cout << endl;
    if(stack.pop(userdata)){
        cout << "popped = success" << endl;
        cout << "ID: " << userdata.id << endl;
        cout << "Information: " << userdata.information << endl;

    } else{
        cout << "Pop underflow error: stack is empty" << endl;
        cout << "ID: " << userdata.id << endl;
        cout << "Information: " << userdata.information << endl;
    }

    cout << endl;


    /*
     * Now perform an exhaustive series of tests on your stack. Push all the
     * cases. Pop all the cases. Randomly push and pop cases. Test peek() and
     * isEmpty() randomly and throughout the other cases. Your tests must be
     * exhaustive! Show all possible ways your stack can be used and abused,
     * and that your stack will gracefully handle ALL cases. You must use
     * automated testing (no user input). Make sure you run your program
     * many times to see what happens when the test cases are bigger, smaller,
     * or the same size as the size of your stack. Also show what happens
     * when you try and push negative ids and/or empty strings, which your
     * stack should not accept.
     */

    /************************************************
******** FILLING AND FULL TESTS *****************
************************************************/

    cout << endl;
    cout << "Testing full operations." << endl;
    cout << "=====================================================" << endl;

    cout << "Filling stack..." << endl;

    // testing filling the stack and overflow
    for(int i = 0; i < number_test_cases; i++){
        string stringData = data[i];
        if(stack.push(ids[i], &stringData)){
            cout << "Pushed ID: "<< ids[i] << endl;
            cout << "Pushed Information: " << stringData << endl;
            cout << endl;
        } else {
            cout << "overflow error: " << ids[i] <<" not pushed" << endl;
            cout << "overflow error: " << stringData <<" not pushed" << endl;
            cout << endl;
        }
    }
    cout << endl;

    // testing isEmpty() on full stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }

    cout << endl;
    cout << endl;

    // testing peek() and pop() on full stack
    if(stack.peek(userdata)){
        cout << "Peek = Success" << endl;
        cout << "Peek ID: "<< userdata.id << endl;
        cout << "Peek Information: " <<userdata.information << endl;
    }else{
        cout << "Peek failure" << endl;
    }
    cout << endl;
    if (stack.pop(userdata)){
        cout << "Pop = Success" << endl;
        cout << "Pop ID: "<< userdata.id << endl;
        cout << "Pop Information: " <<userdata.information << endl;
    }else{
        cout << "Pop failure" << endl;
    }
    cout << endl;
    cout << endl;

    cout << "Dumping stack..." << endl;
    cout << "=====================================================" << endl;

    // this is a programmer debug routine used for
    // testing and is not part of normal stack methods
    stack.dumpStack();
    cout << endl;

    /************************************************
 ******** EMPTYING AND EMPTY TESTS ***************
 ************************************************/

    cout << "Testing peek and pop, and emptying stack..." << endl;
    cout << "=====================================================" << endl;

    // testing popping and peeking whole stack
    for(int i = 0; i < number_test_cases; i++) {
        if (stack.peek(userdata)) {
            cout << "Peek = Success" << endl;
            cout << "Peek ID: " << userdata.id << endl;
            cout << "Peek Information: " << userdata.information << endl;
        } else {
            cout << "peek underflow error: stack is empty" << endl;
        }
        cout << endl;
        if (stack.pop(userdata)) {
            cout << "Pop = Success" << endl;
            cout << "Pop ID: " << userdata.id << endl;
            cout << "Pop Information: " << userdata.information << endl;
        } else {
            cout << "popped: pop underflow error: stack is empty" << endl;
        }
        cout << endl;

        cout << endl;
        cout << "Dumping stack..." << endl;
        cout << "=====================================================" << endl;
        stack.dumpStack();

    }

    // testing isEmpty() on empty stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }
    cout << endl;

    // testing peek() and pop() on empty stack
    if(stack.peek(userdata)){
        cout << "peeked = success" << endl;
        cout << "ID: " << userdata.id << endl;
        cout << "Information: " << userdata.information << endl;
    } else{
        cout << "Peek underflow error: stack is empty" << endl;
        cout << "ID: " << userdata.id << endl;
        cout << "Information: " << userdata.information << endl;
    }

    cout << endl;
    if(stack.pop(userdata)){
        cout << "popped = success" << endl;
        cout << "ID: " << userdata.id << endl;
        cout << "Information: " << userdata.information << endl;

    } else{
        cout << "Pop underflow error: stack is empty" << endl;
        cout << "ID: " << userdata.id << endl;
        cout << "Information: " << userdata.information << endl;
    }

    cout << endl;

    /************************************************
******** RANDOM TESTS ***************************
************************************************/


    cout << endl;
    cout << "Testing full operations." << endl;
    cout << "=====================================================" << endl;
    cout << endl;

    cout << "Random testing..." << endl;
    // filling the stack half way with random numbers to begin random tests
    int value;

    for (int i = 0; i< int(STACK_SIZE / 2); i++) {
        value = (rand() % MAX_INT) + 1;
        string strValue = std::to_string(value);
        if(stack.push(value, &strValue)){
            cout << "Pushed ID: "<< value << endl;
            cout << "Pushed Information: " << strValue << endl;
        } else {
            cout << "overflow error: " << value<<" not pushed" << endl;
            cout << "overflow error: " << strValue <<" not pushed" << endl;

        }
    }
    cout << endl;

    /*
     * the following will test random operations. push() and pop()
     * are called twice as often as peek and isempty because they
     * change the stack and should be tested more rigorously.
     */


    int choice = rand() % CHOICES + 1;
    for (int i = 0; i < RANDOM_TRIES; i++) {
        value = (rand() % MAX_INT) + 1;
        string strValue = std::to_string(value);
        switch (choice) {
            case 1:
            case 2:{
                // push
                if(stack.push(value, &strValue)){
                    cout << "Pushed ID: "<< value << endl;
                    cout << "Pushed Information: " << strValue << endl;
                }else {
                    cout << "overflow error: " << value <<" not pushed" << endl;
                    cout << "overflow error: " << strValue <<" not pushed" << endl;
                }
                break;
            }
            case 3:
            case 4:
                // pop
                if(stack.pop(userdata)){
                    cout << "popped = success" << endl;
                    cout << "ID: " << userdata.id << endl;
                    cout << "Information: " << userdata.information << endl;

                } else{
                    cout << "Pop underflow error: stack is empty" << endl;
                    cout << "ID: " << userdata.id << endl;
                    cout << "Information: " << userdata.information << endl;
                }

                break;
            case 5:
                // peek
                if(stack.peek(userdata)){
                    cout << "peeked = success" << endl;
                    cout << "ID: " << userdata.id << endl;
                    cout << "Information: " << userdata.information << endl;
                } else{
                    cout << "Peek underflow error: stack is empty" << endl;
                    cout << "ID: " << userdata.id << endl;
                    cout << "Information: " << userdata.information << endl;
                }
                break;
            case 6:
                // isempty
                if (stack.isEmpty()) {
                    cout << "stack is empty" << endl;
                } else {
                    cout << "stack is NOT empty" << endl;
                }
                break;
        }
        choice = rand() % CHOICES + 1;

    }
    cout << endl;

    stack.dumpStack();

    cout << "Testing complete." << endl;


    return 0;
}
