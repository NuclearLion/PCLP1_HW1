1. INFINITE PRODUCT
		First step here is initializing everything with 0, except the maximums,
	which I initialise with -1, because I need a distinct value which cannot
	be read from input. So, if I find no 2nd max value, I'm sure that max2_a
	or max2_b are -1. It is really important that sum_n_a/b are delcared as
	double. If they were delcared as integers, the sqrt function couldn't  
	calculate exact values, and would return random decimals;
		My program calculates everything at imput, so it doesn't have to save
	anything in any array. First I read base8_a/b from stdin, but the next
	step is transforming them into 10th base with the base_8_10 function;
		Next thing is calculating the scalar product as (a1 * b1) +...+
	+ (an * bn);
		Next is calculating the 2nd max of a and b; in order to do that, I
	firstly need to find the "1st" maximum in order to compare the 2nd to that;
		Last, but not least, is calculating the n_a and n_b as
	n_a = sqrt(a1^2 + a2^2 + ... + an^2) in a double variable (chosen because 
	of the 15 > 7 decimal precision);
		Now we can display at stdout the calculated values.
		OBSERVATION: in case we have every value of a / b as being 1, except
	one of them, than we can mathematicaly consider that in the scalar product
	there was already calculated the n_a/b value.	

2. SIMPLE QUERIES
		I'm saving the number of times every letter apears in a frequency array
	in order to make a lot of queries in a short time. This array needs to be
	initialised with 0 everywhere;
		I have to init with 0 some important variables: current_index
	represents the total of numbers inside the frequency vector and is reduced
	when we execute the E query; the unic variable is used as a boolen in order
	to determine if there are at least 2 different letters inside the array;
	we use c_ant(erior) in order to determine this thing by copairing it to the
	(current) c; in variable last_alert we count how many letters were imuted
	since the last alert; cnt_letters_all counts the current_index + deleted
	letters;
		I read every letter separately, so while reading I can already perform
	queries.
		If the readen value is a small letter, than I have to add it inside the
	frequency array, count a new letter and count a new step since the last
	alert; now I have to check if there is only one unique letter and check
	if an alert is needed (using the alert() function); the alert() needs only
	the earlier mentioned variables. It checks if there are only unique
	letters, if the current input is greater than 5 and if there were at least
	5 new letters since the last alert. If there is the case, it displays an
	alert, and the ratio is reduced by using math (a fractios is reductible by
	the cmmdc of the 2 numbers);
		If the readen value is a grat letter, the program has to stop, except
	if the letters is Q, E or T; 
	if Q is readen, I display the value of aparitions of the next character
	readen;
	if E, I delete the frequency of the next readen character, and substract
	it's value from the current current_index
	if T, I interogate the frequency array by ussing the interog(); it creates
	a copy of the freq array and sorts it by 2 criterias: freq first an 2nd is
	the lexicographical order; later it only displays the letters, without
	their freq;
	NOTE: I use getchar() in order to step over the '\n' characterwhile
	reading
	NOTE: I read everything inside a while loop, until an invalid letter is
	readen

3. GIGEL AND THE CHECKBOARD
		I initialise the value moves with 0 because it is the value of the total
	moves the piece makes inside the board; Values current_i/j represent the
	coordinates of this piece;
		I start iterating through the board in a while loop, until the value of
	the current square is 0;
		I use value current_step for saving the value of current square before
	replacing it with 0 inside the board; 
		I obbserved that if there is a white square than it's coordinates have
	the same parity, else it is black;
		Next step is modifing the current_i/j by adding the current step; if
	the new value it's outside the board, I have to bring it back inside the
	parameters by repetead substraction if the value it's too big, or by 
	asserting the value of border - current if the value is negative; this is
	valid for both cases (i/j);
		Because of the fact that the checkboard is numbered starting from the
	lower left corner, my current i has to be transformed so it becomes 
	border - i;
		In the end, I have to show the number of total moves, and the last
	coordinates of the chess piece; The i was calculated earlier, but I have
	to transform the j to letters. if j > 26, it has to be shown by 2 letters;	

4. ANOTHER QUERIES
		Basically I'm reading the 2D array and saving it in memory and than
	reading and executing operations on it, which I have organised in funcs:
		op1: checks every number 1...n*n if are on the line, and displays if
	it could fit on the line
		op2: same thing, but on columns
		op3: same thing, but inside a n*n square
		op4: checks if a value could be on given coordinates by using the
	earlier implemented functios: checks if it would be unique on it's line,
	column and inside it's square; also it check's if the square at those
	coords is empty;
		op5: checks if the square at given coords is free and if it is, places
	a given value inside it
		op6: checks if the game is won, can continue, or there was made a
	mistake when placing a new number by verifing if there are any duplicate
	numbers on the same column or line by using a frequency array; if there
	are duplicates, it has to show 1, if there are no duplicates, but there
	still are 0s inside, than the game can be resumed so it has to display 0,
	but if there is no conflic, and no 0s, it means the table is full and
	the game is won, so it has to display 2.
