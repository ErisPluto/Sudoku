<h1 align = "center">Debug Record</h1>
<div align = "right">
	<p><i>Project:Sudoku - Personal Project</i></p>
	<p><i>Start Date:2017/09/19</i></p>
	<p><i>Administrator: Eris Pluto</i></p>
</div>
<div>
	<table>
		<colgroup>
			<col style = "width: 10%">
			<col style = "width: 20%">
			<col style = "width: 40%">
			<col style = "width: 5%">
			<col style = "width: 5%">
			<col style = "width: 10%">			
		</colgroup>
		<thead>
		<tr>
			<th>Seq</th>
			<th>Title</th>
			<th>Con/Sol</th>
			<th>O</th>
			<th>S</th>
			<th>Date</th>
		</tr>
		</thead>
		<tbody style = "font-size:15px">
		<tr>
			<td>1</td>
			<td>Mixtakes about "&&" and "||"</td>
			<td>When decide which character to choose, set the condition as "||" by mistake<hr>Changed it to "&&"</td>
			<td>A</td>
			<td>S</td>
			<td>9/22</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Repeation may happen if the request number is large enough</td>
			<td></td>
			<td>B</td>
			<td>N</td>
			<td>9/23</td>
		</tr>
		<tr>
			<td>3</td>
			<td>The append mode to open files can cause chaos</td>
			<td>Just generate sudokus and solve puzzles in a same file and append to the file continuously.<hr>Set a argment when output and clean the file before using it by opening it in 'out' mode</td>
			<td>B</td>
			<td>S</td>
			<td>9/23</td>
		</tr>
		</tbody>
	</table>
	<h6>Note</h6>
	<ul>
		<li><i>The behavior should be described breifly in column 'Title'</i></li>
		<li><i>The position, situation, possible samples to evoke this bug, reasons and solutions,should be write in column 'Con'</i></li>
		<li><i>Three ranks can be set for Order
			<ul>
				<li>A: Very serious and this progress cannot go on until this bug is solved</li>
				<li>B: Serious and the functions and results can be affected if this bug is kept</li>
				<li>C: It is still okay now, but following progress will be affected or this point is just being doubted and is not proved to be a bug</li>
			</ul>
		</i></li>
		<li><i>In the column 'Status':
			<ul>
				<li>'R' means 'Reason has been gotten'</li>
				<li>'N' means 'Nothing has been done'</li>				
				<li>'S' means 'Settled this bug'</li>
				<li>'M' means 'Take this point as a bug by mistake'</li>
				<li>'D' means 'Doubt that this resolved bug is related to some strange behaviors'</li>
			</ul>
		</i></li>
		<li>The last modified date should be recorded in column 'Date'</li>
	</ul>

</div>