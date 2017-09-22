<h1 align = "center">Design for Sudoku</h1>
<div align = "right"><i>2017-09-21 <b>Edition 1</b></i></div>
<hr>
<div>
	<h2>Modules</h2>
	<ol><i>This project is divided into the following five part logically, and will be described relatively detailed here.</i>
		<li>The interface for the command line.
			<ul>
				<li>-t (int)random_number</li>
				<li>-s (char*)absolute_path</li>
				<li>*-i <b>(Proposal 2)</b></li>
			</ul>
		</li>
		<li>The function to generate the sudoku
			<ul>
				<li>Using Backtracing Algrithm to get the sudokus</li>
				<li>Using recursive function/ Using cycle</li>
				<li>Generate sudokus according to the random parts <b>(Proposal 1)</b>/ Generate all sudokus in a initial pricess before using it <b>(Proposal 2)</b></li>
			</ul>
		</li>
		<li>The function to get the sudokus
			<ul>
				<li>Generate parts of sudokus randomly <b>(Proposal 1)</b>/ Get sudokus using random index it, and get them randomly <b>(Proposal 2)</b></li>
			</ul>
		</li>
		<li>The function to solve the sudoku puzzle
			<ul>
				<li>Use the same way as generate sudokus</li>
			</ul>
		</li>
		<li>The function the output the sudokus and puzzles to files</li>
	</ol>
</div>
<div>
	<h2>Proposals</h2>
	<ul><i>This part is used to deal with the problem how to generate the sudokus randomly and effctively</i>
		<li>
			<h4>Proposal 1</h4>
			<p>&nbsp;&nbsp;Generate the sudokus only when needed, when generate the sudokus, init each sudoku by filling in three squares in the diagnal randomly but according to the non-repeating rule. In this step, it should be made sure that <b>each sudoku has different initial state.</b></p>
			<ul>Evaluation
				<li>Advantages:
					<ul>
						<li>The content of sudokus will not be given away.</li>
					</ul>
				</li>
				<li>Disadvantages:
					<ul>
						<li>The generation step may be time-costly, and it may be difficult to avoid repeatation when the requested number is large</li>
					</ul>
				</li>
			</ul>
		</li>
		<li>
			<h4>Proposal 2</h4>
			<p>&nbsp;&nbsp;Generate all the sudokus before using generate function and store the encoded strings in a text file. Generate random number as index to fetch the record of sudokus. <b>Random number should be non-repeating.</b></p>
			<ul>Evaluation
				<li>Advantages:
					<ul>
						<li>Once it is initialized, no need to waste any time to do complex random work.</li>
						<li>Save time in generating sudokus</li>
					</ul>
				</li>
				<li>Disadvantages:
					<ul>
						<li>The initial process may be time-costly</li>
						<li>The security of sudokus in the external cannot be asured</li>
					</ul>
				</li>
			</ul>
		</li>
	</ul>
</div>
<hr>

<div>
	<h2>Detailed Design</h2>
	<ul><i>This part is used to deal with the problem how to generate the sudokus randomly and effctively</i>
		<li>
			<h4>Functions</h4>
			<ul>
				<li>int main(int argc, char* args[]);
					<ul>
						<li>In the 't' mode, call GetSudokus() to get certain number of sudokus according to the argment</li>
						<li>In the 's' mode, call SolveSodukus() to solve sudoku  puzzle.</li>
					</ul>
				</li>
				<li>void GetSudokus()
					<ul>
						<li>If the file 'AllSudokus' exists, just read random index of lines from the file and call CreateSudokus() to create sudokus.</li>
						<li>If the file 'AllSudokus' does not exist, call GenerateSudokus to generate sudokus</li>
					</ul>
				</li>
				<li>int** GenerateSudokus()
					<ul>
						<li>Using backtracing algrithm to generate sudokus, circulate from initSet[0] to initSet[8] to choose a proper number to fill in each position.</li>
						<li>If there is no proper number, return to the last function</li>
						<li>When the last position is reached output it to file</li>
					</ul>
				</li>
				<li>int** CreateSudokus(char *sudokuString)
					<ul>
						<li>Generate sudokus from strings read from file 'AllSudokus'</li>
					</ul>
				</li>
				<li>void InitSudokus()
					<ul>
						<li>Set the argment and call GenerateSudokus() to create all the sudokus and Call FileOutput() to output the sudokus to 'AllSudokus'</li>
					</ul>
				</li>
				<li>int* InitSet()
					<ul>
						<li>Init the set of 1 - 9 in a random sequence, make sure that sets are different from each other.</li>
					</ul>
				</li>
				<li>int** SolvePuzzles()
					<ul>
						<li>Call FileInput to get sudoku puzzles</li>
						<li>Call GenerateSudoku() to generate sudoku based on the puzzle</li>
					</ul>
				</li>
				<li>void FileOutput(char* name, char* path)
					<ul>
						<li>Create the file 'name' in 'path', and output the content into it</li>
					</ul>
				</li>
				<li>void FileInput(char* name, char* path)
					<ul>
						<li>Read sudoku puzzles from the file 'name' in 'path', and change the strings into two-demension array</li>
					</ul>
				</li>
			</ul>
		</li>
	</ul>
</div>
<hr>

<div>
	<h4>Notes</h4>
	<ul>
		<li>Empty</li>
	</ul>
</div>