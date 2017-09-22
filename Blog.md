<h1 align = "center">个人项目-数独</h1>
<hr>
<a href = "https://github.com/ErisPluto/Sudoku">My Sudoku——https://github.com/ErisPluto/Sudoku</a>
<div>
	<h3>估计时间</h3>
	<table>
		<colgroup>
			<col style = "width :25%">
			<col style = "width :45%">
			<col style = "width :15%">
			<col style = "width :15%">
		</colgroup>
		<tr>
			<th>PSP2.1</th>
			<th>Personal Software Process Stages</th>
			<th>预估耗时（分钟）</th>
			<th>实际耗时（分钟）</th>
		</tr>
		<tr>
			<td>Planning</td>
			<td>计划</td>
			<td>30</td><td></td>
		</tr>
		<tr>
			<td><li>Estimate</li></td>
			<td><li>估计这个任务需要多少时间</li></td>
			<td>30</td><td></td>
		</tr>
		<tr>
			<td>Development</td>
			<td>开发</td>
			<td>690</td><td></td>
		</tr>
		<tr>
			<td><li>Analysis</li></td>
			<td><li>需求分析 (包括学习新技术)</li></td>
			<td>150</td><td></td>
		</tr>
		<tr>
			<td><li>Design Spec</li></td>
			<td><li>生成设计文档</li></td>
			<td>60</td><td></td>
		</tr>		
		<tr>
			<td><li>Design Review</li></td>
			<td><li>设计复审 (和同事审核设计文档)</li></td>
			<td>30</td><td></td>
		</tr>		
		<tr>
			<td><li>Coding Standard</li></td>
			<td><li>代码规范 (为目前的开发制定合适的规范)</li></td>
			<td>60</td><td></td>
		</tr>	
		<tr>
			<td><li>Design</li></td>
			<td><li>具体设计</li></td>
			<td>120</td><td></td>
		</tr>		
		<tr>
			<td><li>Coding</li></td>
			<td><li>具体编码</li></td>
			<td>90</td><td></td>
		</tr>		
		<tr>
			<td><li>Code Reviewg</li></td>
			<td><li>代码复审</li></td>
			<td>60</td><td></td>
		</tr>		
		<tr>
			<td><li>Test</li></td>
			<td><li>测试（自我测试，修改代码，提交修改）</li></td>
			<td>120</td><td></td>
		</tr>
		<tr>
			<td>Reporting</td>
			<td>报告</td>
			<td>180</td><td></td>
		</tr>
		<tr>
			<td><li>Test Report</li></td>
			<td><li>测试报告</li></td>
			<td>90</td><td></td>
		</tr>		
		<tr>
			<td><li>Size Measurement</li></td>
			<td><li>计算工作量</li></td>
			<td>30</td><td></td>
		</tr>
		<tr>
			<td><li>Postmortem & Process Improvement Plan</li></td>
			<td><li>事后总结, 并提出过程改进计划</li></td>
			<td>60</td><td></td>
		</tr>
		<tr>
			<td>Sum</td>
			<td>合计</td>
			<td>900</td><td></td>
		</tr>
	</table>
</div>
<div>
	<h3>解题思路</h3>
	<ol>
		<li>理解题目功能需求，即设计程序生成数独终局，分为三部分:
			<ul>
				<li>生成终局</li>
				<li>求解数独</li>
				<li>GUI设计（可选）</li>
			</ul>
		</li>
		<li>理解题目相关细节。
			<ul>
				<li>github建立项目，相关命名（sudoku.exe、 sudoku.txt）、路径规范（BIN文件夹）</li>
				<li>输出到文件</li>
				<li>命令行加参数运行程序</li>
				<li>使用C++或C#完成程序</li>
			</ul>
		</li>
		<li>明确后续所需处理
			<ul>
				<li>消除所有警告</li>
				<li>寻找并改进性能瓶颈</li>
				<li>进行单元测试，测试覆盖率，准备测试用例</li>
			</ul>
		</li>
		<li>初步思考可能需要的技术、工具，可能遇到的问题：
			<ul>
				<li>Code Quality Analysis工具</li>
				<li>Studio Profiling Tools</li>
				<li>OpenCppCoverage</li>
				<li>生成终局所需要的算法</li>
				<li>命令行参数的使用</li>
				<li>输出到文件所需要的函数</li>
				<li>学习C++或C#</li>
			</ul>
		</li>
	</ol>
</div>
<div>
	<h3>设计实现</h3>
</div>
<div>
	<h3>性能改进</h3>
</div><div>
	<h3>代码说明</h3>
</div>
<div>
	<h3>实际时间</h3>
	<table>
		<colgroup>
			<col style = "width :25%">
			<col style = "width :45%">
			<col style = "width :15%">
			<col style = "width :15%">
		</colgroup>
		<tr>
			<th>PSP2.1</th>
			<th>Personal Software Process Stages</th>
			<th>预估耗时（分钟）</th>
			<th>实际耗时（分钟）</th>
		</tr>
		<tr>
			<td>Planning</td>
			<td>计划</td>
			<td>30</td><td>30</td>
		</tr>
		<tr>
			<td><li>Estimate</li></td>
			<td><li>估计这个任务需要多少时间</li></td>
			<td>30</td><td>30</td>
		</tr>
		<tr>
			<td>Development</td>
			<td>开发</td>
			<td>690</td><td></td>
		</tr>
		<tr>
			<td><li>Analysis</li></td>
			<td><li>需求分析 (包括学习新技术)</li></td>
			<td>150</td><td>180</td>
		</tr>
		<tr>
			<td><li>Design Spec</li></td>
			<td><li>生成设计文档</li></td>
			<td>60</td><td>40</td>
		</tr>		
		<tr>
			<td><li>Design Review</li></td>
			<td><li>设计复审(和同事审核设计文档)</li></td>
			<td>30</td><td></td>
		</tr>		
		<tr>
			<td><li>Coding Standard</li></td>
			<td><li>代码规范 (为目前的开发制定合适的规范)</li></td>
			<td>60</td><td></td>
		</tr>	
		<tr>
			<td><li>Design</li></td>
			<td><li>具体设计</li></td>
			<td>120</td><td></td>
		</tr>		
		<tr>
			<td><li>Coding</li></td>
			<td><li>具体编码</li></td>
			<td>90</td><td></td>
		</tr>		
		<tr>
			<td><li>Code Reviewg</li></td>
			<td><li>代码复审</li></td>
			<td>60</td><td></td>
		</tr>		
		<tr>
			<td><li>Test</li></td>
			<td><li>测试（自我测试，修改代码，提交修改）</li></td>
			<td>120</td><td></td>
		</tr>
		<tr>
			<td>Reporting</td>
			<td>报告</td>
			<td>180</td><td></td>
		</tr>
		<tr>
			<td><li>Test Report</li></td>
			<td><li>测试报告</li></td>
			<td>90</td><td></td>
		</tr>		
		<tr>
			<td><li>Size Measurement</li></td>
			<td><li>计算工作量</li></td>
			<td>30</td><td></td>
		</tr>
		<tr>
			<td><li>Postmortem & Process Improvement Plan</li></td>
			<td><li>事后总结, 并提出过程改进计划</li></td>
			<td>60</td><td></td>
		</tr>
		<tr>
			<td>Sum</td>
			<td>合计</td>
			<td>900</td><td></td>
		</tr>
	</table>
</div>