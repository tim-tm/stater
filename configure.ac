AC_PREREQ([2.72])
AC_INIT([stater], [0.1], [teichmanntim@outlook.de])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([m], [fabs], [], [AC_MSG_ERROR(["Problem with math library: fabs not found"])])
AC_CHECK_LIB([raylib], [SetConfigFlags], [], [AC_MSG_ERROR(["Problem with raylib: SetConfigFlags not found"])])
AC_CHECK_LIB([raylib], [InitWindow], [], [AC_MSG_ERROR(["Problem with raylib: InitWindow not found"])])
AC_CHECK_LIB([raylib], [SetTargetFPS], [], [AC_MSG_ERROR(["Problem with raylib: SetTargetFPS not found"])])
AC_CHECK_LIB([raylib], [SetWindowMinSize], [], [AC_MSG_ERROR(["Problem with raylib: SetWindowMinSize not found"])])
AC_CHECK_LIB([raylib], [WindowShouldClose], [], [AC_MSG_ERROR(["Problem with raylib: WindowShouldClose not found"])])
AC_CHECK_LIB([raylib], [CloseWindow], [], [AC_MSG_ERROR(["Problem with raylib: CloseWindow not found"])])
AC_CHECK_LIB([raylib], [BeginDrawing], [], [AC_MSG_ERROR(["Problem with raylib: BeginDrawing not found"])])
AC_CHECK_LIB([raylib], [ClearBackground], [], [AC_MSG_ERROR(["Problem with raylib: ClearBackground not found"])])
AC_CHECK_LIB([raylib], [EndDrawing], [], [AC_MSG_ERROR(["Problem with raylib: EndDrawing not found"])])
AC_CHECK_LIB([raylib], [DrawText], [], [AC_MSG_ERROR(["Problem with raylib: DrawText not found"])])
AC_CHECK_LIB([raylib], [DrawRectangleLines], [], [AC_MSG_ERROR(["Problem with raylib: DrawRectangleLines not found"])])
AC_CHECK_LIB([raylib], [DrawLineEx], [], [AC_MSG_ERROR(["Problem with raylib: DrawLinesEx not found"])])
AC_CHECK_LIB([raylib], [TextFormat], [], [AC_MSG_ERROR(["Problem with raylib: TextFormat not found"])])
AC_CHECK_LIB([raylib], [MeasureText], [], [AC_MSG_ERROR(["Problem with raylib: MeasureText not found"])])
AC_CHECK_LIB([raylib], [GetMouseX], [], [AC_MSG_ERROR(["Problem with raylib: GetMouseX not found"])])
AC_CHECK_LIB([raylib], [GetMouseY], [], [AC_MSG_ERROR(["Problem with raylib: GetMouseY not found"])])
AC_CHECK_LIB([raylib], [DrawLine], [], [AC_MSG_ERROR(["Problem with raylib: DrawLine not found"])])
AC_CHECK_LIB([raylib], [DrawCircle], [], [AC_MSG_ERROR(["Problem with raylib: DrawCircle not found"])])
AC_CHECK_LIB([raylib], [GetScreenWidth], [], [AC_MSG_ERROR(["Problem with raylib: GetScreenWidth not found"])])
AC_CHECK_LIB([raylib], [GetScreenHeight], [], [AC_MSG_ERROR(["Problem with raylib: GetScreenHeight not found"])])

AC_CHECK_HEADERS([float.h], [], [AC_MSG_ERROR([Could not find float.h])])
AC_CHECK_HEADERS([raylib.h], [], [AC_MSG_ERROR([Could not find raylib.h])])
AC_CHECK_HEADERS([math.h], [], [AC_MSG_ERROR([Could not find math.h])])

AC_FUNC_MALLOC
AC_FUNC_REALLOC

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
