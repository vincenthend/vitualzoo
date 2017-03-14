FOR /f "tokens=1 delims=." %%a IN ('dir /b /a-d "*.cpp"') DO (
	MD %%a
	MOVE "%%a.*" .\%%a\
)