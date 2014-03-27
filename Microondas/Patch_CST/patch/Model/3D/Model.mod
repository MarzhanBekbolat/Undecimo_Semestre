'# MWS Version: Version 2011.0 - Jan 15 2011 - 04:38:39 - ACIS 21.0.0 -

'# length = mm
'# frequency = GHz
'# time = ns
'# frequency range: fmin = 1.4 fmax = 3.4


'@ use template: Antenna (Planar)

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
' Template for Antenna in Free Space
' ==================================

' (CSTxMWSxONLY)

' draw the bounding box

Plot.DrawBox True

' set units to mm, ghz

With Units 
     .Geometry "mm" 
     .Frequency "ghz" 
     .Time "ns" 
End With 

' set background material to vacuum

With Background 
     .Type "Normal" 
     .Epsilon "1.0" 
     .Mue "1.0" 
     .XminSpace "0.0" 
     .XmaxSpace "0.0" 
     .YminSpace "0.0" 
     .YmaxSpace "0.0" 
     .ZminSpace "0.0" 
     .ZmaxSpace "0.0" 
End With 

' set boundary conditions to open

With Boundary
     .Xmin "expanded open" 
     .Xmax "expanded open" 
     .Ymin "expanded open" 
     .Ymax "expanded open" 
     .Zmin "expanded open" 
     .Zmax "expanded open" 
     .Xsymmetry "none" 
     .Ysymmetry "none" 
     .Zsymmetry "none" 
End With

' optimize mesh settings for planar structures

With Mesh 
     .MergeThinPECLayerFixpoints "True" 
     .RatioLimit "20" 
     .AutomeshRefineAtPecLines "True", "6"
     .FPBAAvoidNonRegUnite "True" 
     .ConsiderSpaceForLowerMeshLimit "False" 
     .MinimumStepNumber "5" 
End With 

MeshSettings.SetMeshType "HexTLM" 

With MeshSettings 
     .Set "RatioLimitGeometry", "20" 
End With 


' change mesh adaption scheme to energy 
' 		(planar structures tend to store high energy 
'     	 locally at edges rather than globally in volume)

MeshAdaption3D.SetAdaptionStrategy "Energy" 

' switch on FD-TET setting for accurate farfields

FDSolver.ExtrudeOpenBC "True" 

'@ set workplane properties

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With WCS
     .SetWorkplaneSize "100"
     .SetWorkplaneRaster "10"
     .SetWorkplaneAutoadjust "True"
     .SetWorkplaneSnap "True"
     .SetWorkplaneSnapRaster "0.01"
     .SetWorkplaneSnapAutoadjust "True"
End With


'@ activate local coordinates

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
WCS.ActivateWCS "local"


'@ new component: component1

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
Component.New "component1" 


'@ define brick: component1:subs

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Brick
     .Reset 
     .Name "subs" 
     .Component "component1" 
     .Material "Vacuum" 
     .Xrange "-w", "w" 
     .Yrange "-(2*l+l1+l2)/2", "(2*l+l1+l2)/2" 
     .Zrange "0", "h" 
     .Create
End With


'@ delete shape: component1:subs

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
Solid.Delete "component1:subs" 


'@ define material: FR-4 (lossy)

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Material
     .Reset
     .Name "FR-4 (lossy)"
.FrqType "all" 
.Type "Normal" 
.SetMaterialUnit "GHz", "mm"
.Epsilon "4.3" 
.Mue "1.0" 
.Kappa "0.0" 
.TanD "0.025" 
.TanDFreq "10.0" 
.TanDGiven "True" 
.TanDModel "ConstTanD" 
.KappaM "0.0" 
.TanDM "0.0" 
.TanDMFreq "0.0" 
.TanDMGiven "False" 
.TanDMModel "ConstKappa" 
.DispModelEps "None" 
.DispModelMue "None" 
.DispersiveFittingSchemeEps "General 1st" 
.DispersiveFittingSchemeMue "General 1st" 
.UseGeneralDispersionEps "False" 
.UseGeneralDispersionMue "False" 
.Rho "0.0" 
.ThermalType "Normal" 
.ThermalConductivity "0.3" 
.SetActiveMaterial "all" 
.Colour "0.94", "0.82", "0.76" 
.Wireframe "False" 
.Transparency "0" 
.Create
End With 


'@ define brick: component1:subs

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Brick
     .Reset 
     .Name "subs" 
     .Component "component1" 
     .Material "FR-4 (lossy)" 
     .Xrange "-w", "w" 
     .Yrange "-(2*l+l1+l2)/2", "(2*l+l1+l2)/2" 
     .Zrange "0", "h" 
     .Create
End With


'@ pick face

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
Pick.PickFaceFromId "component1:subs", "2" 


'@ align wcs with face

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
WCS.AlignWCSWithSelected "Face"


'@ pick face

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
Pick.PickFaceFromId "component1:subs", "2" 


'@ define extrude: component1:gnd

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Extrude 
     .Reset 
     .Name "gnd" 
     .Component "component1" 
     .Material "FR-4 (lossy)" 
     .Mode "Picks" 
     .Height "t" 
     .Twist "0.0" 
     .Taper "0.0" 
     .UsePicksForHeight "False" 
     .DeleteBaseFaceSolid "False" 
     .ClearPickedFace "True" 
     .Create 
End With 


'@ delete shape: component1:gnd

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
Solid.Delete "component1:gnd" 


'@ pick face

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
Pick.PickFaceFromId "component1:subs", "2" 


'@ define material: Copper (annealed)

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Material
     .Reset
     .Name "Copper (annealed)"
.FrqType "static" 
.Type "Normal" 
.SetMaterialUnit "Hz", "mm" 
.Epsilon "1" 
.Mue "1.0" 
.Kappa "5.8e+007" 
.TanD "0.0" 
.TanDFreq "0.0" 
.TanDGiven "False" 
.TanDModel "ConstTanD" 
.KappaM "0" 
.TanDM "0.0" 
.TanDMFreq "0.0" 
.TanDMGiven "False" 
.TanDMModel "ConstTanD" 
.DispModelEps "None" 
.DispModelMue "None" 
.DispersiveFittingSchemeEps "1st Order" 
.DispersiveFittingSchemeMue "1st Order" 
.UseGeneralDispersionEps "False" 
.UseGeneralDispersionMue "False" 
.FrqType "all" 
.Type "Lossy metal" 
.SetMaterialUnit "GHz", "mm" 
.Mue "1.0" 
.Kappa "5.8e+007" 
.Rho "8930.0" 
.ThermalType "Normal" 
.ThermalConductivity "401.0" 
.HeatCapacity "0.39" 
.MetabolicRate "0" 
.BloodFlow "0" 
.VoxelConvection "0" 
.MechanicsType "Isotropic" 
.YoungsModulus "120" 
.PoissonsRatio "0.33" 
.ThermalExpansionRate "17" 
.Colour "1", "1", "0" 
.Wireframe "False" 
.Reflection "False" 
.Allowoutline "True" 
.Transparentoutline "False" 
.Transparency "0" 
.Create
End With 


'@ define extrude: component1:gnd

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Extrude 
     .Reset 
     .Name "gnd" 
     .Component "component1" 
     .Material "Copper (annealed)" 
     .Mode "Picks" 
     .Height "t" 
     .Twist "0.0" 
     .Taper "0.0" 
     .UsePicksForHeight "False" 
     .DeleteBaseFaceSolid "False" 
     .ClearPickedFace "True" 
     .Create 
End With 


'@ pick face

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
Pick.PickFaceFromId "component1:subs", "1" 


'@ align wcs with face

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
WCS.AlignWCSWithSelected "Face"


'@ define brick: component1:patch

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Brick
     .Reset 
     .Name "patch" 
     .Component "component1" 
     .Material "Copper (annealed)" 
     .Xrange "-w/2", "w/2" 
     .Yrange "-(2*l+l1+l2)/2+l1+l2", "(2*l+l1+l2)/2-l" 
     .Zrange "0", "t" 
     .Create
End With


'@ define brick: component1:line1

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Brick
     .Reset 
     .Name "line1" 
     .Component "component1" 
     .Material "Copper (annealed)" 
     .Xrange "-w1/2", "w1/2" 
     .Yrange "-(2*l+l1+l2)/2+l2", "-(2*l+l1+l2)/2+l2+l1" 
     .Zrange "0", "t" 
     .Create
End With


'@ define brick: component1:line2

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Brick
     .Reset 
     .Name "line2" 
     .Component "component1" 
     .Material "Copper (annealed)" 
     .Xrange "-w2/2", "w2/2" 
     .Yrange "-(2*l+l1+l2)/2", "-(2*l+l1+l2)/2+l2" 
     .Zrange "0", "t" 
     .Create
End With


'@ boolean add shapes: component1:patch, component1:line1

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Solid 
     .Version 9
     .Add "component1:patch", "component1:line1" 
     .Version 1
End With 


'@ boolean add shapes: component1:patch, component1:line2

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Solid 
     .Version 9
     .Add "component1:patch", "component1:line2" 
     .Version 1
End With 


'@ pick face

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
Pick.PickFaceFromId "component1:patch", "3" 


'@ define port: 1

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Port 
     .Reset 
     .PortNumber "1" 
     .Label "" 
     .NumberOfModes "1" 
     .AdjustPolarization "False" 
     .PolarizationAngle "0.0" 
     .ReferencePlaneDistance "0" 
     .TextSize "50" 
     .Coordinates "Picks" 
     .Orientation "positive" 
     .PortOnBound "True" 
     .ClipPickedPortToBound "False" 
     .Xrange "-0.585915", "0.585915" 
     .Yrange "-47.724112171", "-47.724112171" 
     .Zrange "0.711", "0.811" 
     .XrangeAdd "3*w2", "3*w2" 
     .YrangeAdd "0.0", "0.0" 
     .ZrangeAdd "h+t", "4*h" 
     .SingleEnded "False" 
     .Create 
End With 


'@ define frequency range

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
Solver.FrequencyRange "1.4", "3.4" 


'@ define monitor: h-field (f=2.4)

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Monitor 
     .Reset 
     .Name "h-field (f=2.4)" 
     .Dimension "Volume" 
     .Domain "Frequency" 
     .FieldType "Hfield" 
     .Frequency "2.4" 
     .Create 
End With 


'@ define farfield monitor: farfield (f=2.4)

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Monitor 
     .Reset 
     .Name "farfield (f=2.4)" 
     .Domain "Frequency" 
     .FieldType "Farfield" 
	    .Frequency "2.4" 
     .Create 
End With 


'@ define solver parameters

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
Mesh.SetCreator "High Frequency" 

With Solver 
     .CalculationType "TD-S"
     .StimulationPort "All"
     .StimulationMode "All"
     .SteadyStateLimit "-30.0"
     .MeshAdaption "False"
     .AutoNormImpedance "False"
     .NormingImpedance "50"
     .CalculateModesOnly "False"
     .SParaSymmetry "False"
     .StoreTDResultsInCache  "False"
     .FullDeembedding "False"
     .SuperimposePLWExcitation "False"
     .UseSensitivityAnalysis "False"
End With


'@ set pba mesh type

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
Mesh.MeshType "PBA"

'@ define monitor: h-energy (f=2.4)

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Monitor 
     .Reset 
     .Name "h-energy (f=2.4)" 
     .Dimension "Volume" 
     .Domain "Frequency" 
     .FieldType "Henergy" 
     .Frequency "2.4" 
     .Create 
End With 


'@ define monitor: power (f=2.4)

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Monitor 
     .Reset 
     .Name "power (f=2.4)" 
     .Dimension "Volume" 
     .Domain "Frequency" 
     .FieldType "Powerflow" 
     .Frequency "2.4" 
     .Create 
End With 


'@ define monitor: current (f=2.4)

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Monitor 
     .Reset 
     .Name "current (f=2.4)" 
     .Dimension "Volume" 
     .Domain "Frequency" 
     .FieldType "Current" 
     .Frequency "2.4" 
     .Create 
End With 


'@ define monitor: loss (f=2.4)

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Monitor 
     .Reset 
     .Name "loss (f=2.4)" 
     .Dimension "Volume" 
     .Domain "Frequency" 
     .FieldType "Powerloss" 
     .Frequency "2.4" 
     .Create 
End With 


'@ define monitor: e-energy (f=2.4)

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
With Monitor 
     .Reset 
     .Name "e-energy (f=2.4)" 
     .Dimension "Volume" 
     .Domain "Frequency" 
     .FieldType "Eenergy" 
     .Frequency "2.4" 
     .Create 
End With 


'@ switch working plane

'[VERSION]2011.0|21.0.0|20110114[/VERSION]
Plot.DrawWorkplane "false" 


