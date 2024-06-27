   RubiksCube3dArray cube;
   cube.print();

   vector<RubiksCube::Move> shuffle_moves = cube.randomShuffleCube(6);
   for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
   cout << "\n";
   cube.print();

   DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 8);
   vector<RubiksCube::Move> solve_moves = dfsSolver.solve();

   for (auto move: solve_moves) cout << cube.getMove(move) << " ";
   cout << "\n";
   dfsSolver.rubiksCube.print();