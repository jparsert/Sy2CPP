// Generated from /home/julian/coding/Sy2CPP/build/antlr4_runtime/src/antlr4_runtime/tool-testsuite/test/org/antlr/v4/test/tool/JavaLR.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link JavaLRParser}.
 */
public interface JavaLRListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#compilationUnit}.
	 * @param ctx the parse tree
	 */
	void enterCompilationUnit(JavaLRParser.CompilationUnitContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#compilationUnit}.
	 * @param ctx the parse tree
	 */
	void exitCompilationUnit(JavaLRParser.CompilationUnitContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#packageDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterPackageDeclaration(JavaLRParser.PackageDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#packageDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitPackageDeclaration(JavaLRParser.PackageDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#importDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterImportDeclaration(JavaLRParser.ImportDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#importDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitImportDeclaration(JavaLRParser.ImportDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#typeDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterTypeDeclaration(JavaLRParser.TypeDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#typeDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitTypeDeclaration(JavaLRParser.TypeDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#classOrInterfaceDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterClassOrInterfaceDeclaration(JavaLRParser.ClassOrInterfaceDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#classOrInterfaceDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitClassOrInterfaceDeclaration(JavaLRParser.ClassOrInterfaceDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#classOrInterfaceModifiers}.
	 * @param ctx the parse tree
	 */
	void enterClassOrInterfaceModifiers(JavaLRParser.ClassOrInterfaceModifiersContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#classOrInterfaceModifiers}.
	 * @param ctx the parse tree
	 */
	void exitClassOrInterfaceModifiers(JavaLRParser.ClassOrInterfaceModifiersContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#classOrInterfaceModifier}.
	 * @param ctx the parse tree
	 */
	void enterClassOrInterfaceModifier(JavaLRParser.ClassOrInterfaceModifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#classOrInterfaceModifier}.
	 * @param ctx the parse tree
	 */
	void exitClassOrInterfaceModifier(JavaLRParser.ClassOrInterfaceModifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#modifiers}.
	 * @param ctx the parse tree
	 */
	void enterModifiers(JavaLRParser.ModifiersContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#modifiers}.
	 * @param ctx the parse tree
	 */
	void exitModifiers(JavaLRParser.ModifiersContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#classDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterClassDeclaration(JavaLRParser.ClassDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#classDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitClassDeclaration(JavaLRParser.ClassDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#normalClassDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterNormalClassDeclaration(JavaLRParser.NormalClassDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#normalClassDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitNormalClassDeclaration(JavaLRParser.NormalClassDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#typeParameters}.
	 * @param ctx the parse tree
	 */
	void enterTypeParameters(JavaLRParser.TypeParametersContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#typeParameters}.
	 * @param ctx the parse tree
	 */
	void exitTypeParameters(JavaLRParser.TypeParametersContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#typeParameter}.
	 * @param ctx the parse tree
	 */
	void enterTypeParameter(JavaLRParser.TypeParameterContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#typeParameter}.
	 * @param ctx the parse tree
	 */
	void exitTypeParameter(JavaLRParser.TypeParameterContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#typeBound}.
	 * @param ctx the parse tree
	 */
	void enterTypeBound(JavaLRParser.TypeBoundContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#typeBound}.
	 * @param ctx the parse tree
	 */
	void exitTypeBound(JavaLRParser.TypeBoundContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#enumDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterEnumDeclaration(JavaLRParser.EnumDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#enumDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitEnumDeclaration(JavaLRParser.EnumDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#enumBody}.
	 * @param ctx the parse tree
	 */
	void enterEnumBody(JavaLRParser.EnumBodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#enumBody}.
	 * @param ctx the parse tree
	 */
	void exitEnumBody(JavaLRParser.EnumBodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#enumConstants}.
	 * @param ctx the parse tree
	 */
	void enterEnumConstants(JavaLRParser.EnumConstantsContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#enumConstants}.
	 * @param ctx the parse tree
	 */
	void exitEnumConstants(JavaLRParser.EnumConstantsContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#enumConstant}.
	 * @param ctx the parse tree
	 */
	void enterEnumConstant(JavaLRParser.EnumConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#enumConstant}.
	 * @param ctx the parse tree
	 */
	void exitEnumConstant(JavaLRParser.EnumConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#enumBodyDeclarations}.
	 * @param ctx the parse tree
	 */
	void enterEnumBodyDeclarations(JavaLRParser.EnumBodyDeclarationsContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#enumBodyDeclarations}.
	 * @param ctx the parse tree
	 */
	void exitEnumBodyDeclarations(JavaLRParser.EnumBodyDeclarationsContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#interfaceDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterInterfaceDeclaration(JavaLRParser.InterfaceDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#interfaceDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitInterfaceDeclaration(JavaLRParser.InterfaceDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#normalInterfaceDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterNormalInterfaceDeclaration(JavaLRParser.NormalInterfaceDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#normalInterfaceDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitNormalInterfaceDeclaration(JavaLRParser.NormalInterfaceDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#typeList}.
	 * @param ctx the parse tree
	 */
	void enterTypeList(JavaLRParser.TypeListContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#typeList}.
	 * @param ctx the parse tree
	 */
	void exitTypeList(JavaLRParser.TypeListContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#classBody}.
	 * @param ctx the parse tree
	 */
	void enterClassBody(JavaLRParser.ClassBodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#classBody}.
	 * @param ctx the parse tree
	 */
	void exitClassBody(JavaLRParser.ClassBodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#interfaceBody}.
	 * @param ctx the parse tree
	 */
	void enterInterfaceBody(JavaLRParser.InterfaceBodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#interfaceBody}.
	 * @param ctx the parse tree
	 */
	void exitInterfaceBody(JavaLRParser.InterfaceBodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#classBodyDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterClassBodyDeclaration(JavaLRParser.ClassBodyDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#classBodyDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitClassBodyDeclaration(JavaLRParser.ClassBodyDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#memberDecl}.
	 * @param ctx the parse tree
	 */
	void enterMemberDecl(JavaLRParser.MemberDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#memberDecl}.
	 * @param ctx the parse tree
	 */
	void exitMemberDecl(JavaLRParser.MemberDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#memberDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterMemberDeclaration(JavaLRParser.MemberDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#memberDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitMemberDeclaration(JavaLRParser.MemberDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#genericMethodOrConstructorDecl}.
	 * @param ctx the parse tree
	 */
	void enterGenericMethodOrConstructorDecl(JavaLRParser.GenericMethodOrConstructorDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#genericMethodOrConstructorDecl}.
	 * @param ctx the parse tree
	 */
	void exitGenericMethodOrConstructorDecl(JavaLRParser.GenericMethodOrConstructorDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#genericMethodOrConstructorRest}.
	 * @param ctx the parse tree
	 */
	void enterGenericMethodOrConstructorRest(JavaLRParser.GenericMethodOrConstructorRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#genericMethodOrConstructorRest}.
	 * @param ctx the parse tree
	 */
	void exitGenericMethodOrConstructorRest(JavaLRParser.GenericMethodOrConstructorRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#methodDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterMethodDeclaration(JavaLRParser.MethodDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#methodDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitMethodDeclaration(JavaLRParser.MethodDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#fieldDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterFieldDeclaration(JavaLRParser.FieldDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#fieldDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitFieldDeclaration(JavaLRParser.FieldDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#interfaceBodyDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterInterfaceBodyDeclaration(JavaLRParser.InterfaceBodyDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#interfaceBodyDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitInterfaceBodyDeclaration(JavaLRParser.InterfaceBodyDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#interfaceMemberDecl}.
	 * @param ctx the parse tree
	 */
	void enterInterfaceMemberDecl(JavaLRParser.InterfaceMemberDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#interfaceMemberDecl}.
	 * @param ctx the parse tree
	 */
	void exitInterfaceMemberDecl(JavaLRParser.InterfaceMemberDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#interfaceMethodOrFieldDecl}.
	 * @param ctx the parse tree
	 */
	void enterInterfaceMethodOrFieldDecl(JavaLRParser.InterfaceMethodOrFieldDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#interfaceMethodOrFieldDecl}.
	 * @param ctx the parse tree
	 */
	void exitInterfaceMethodOrFieldDecl(JavaLRParser.InterfaceMethodOrFieldDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#interfaceMethodOrFieldRest}.
	 * @param ctx the parse tree
	 */
	void enterInterfaceMethodOrFieldRest(JavaLRParser.InterfaceMethodOrFieldRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#interfaceMethodOrFieldRest}.
	 * @param ctx the parse tree
	 */
	void exitInterfaceMethodOrFieldRest(JavaLRParser.InterfaceMethodOrFieldRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#methodDeclaratorRest}.
	 * @param ctx the parse tree
	 */
	void enterMethodDeclaratorRest(JavaLRParser.MethodDeclaratorRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#methodDeclaratorRest}.
	 * @param ctx the parse tree
	 */
	void exitMethodDeclaratorRest(JavaLRParser.MethodDeclaratorRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#voidMethodDeclaratorRest}.
	 * @param ctx the parse tree
	 */
	void enterVoidMethodDeclaratorRest(JavaLRParser.VoidMethodDeclaratorRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#voidMethodDeclaratorRest}.
	 * @param ctx the parse tree
	 */
	void exitVoidMethodDeclaratorRest(JavaLRParser.VoidMethodDeclaratorRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#interfaceMethodDeclaratorRest}.
	 * @param ctx the parse tree
	 */
	void enterInterfaceMethodDeclaratorRest(JavaLRParser.InterfaceMethodDeclaratorRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#interfaceMethodDeclaratorRest}.
	 * @param ctx the parse tree
	 */
	void exitInterfaceMethodDeclaratorRest(JavaLRParser.InterfaceMethodDeclaratorRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#interfaceGenericMethodDecl}.
	 * @param ctx the parse tree
	 */
	void enterInterfaceGenericMethodDecl(JavaLRParser.InterfaceGenericMethodDeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#interfaceGenericMethodDecl}.
	 * @param ctx the parse tree
	 */
	void exitInterfaceGenericMethodDecl(JavaLRParser.InterfaceGenericMethodDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#voidInterfaceMethodDeclaratorRest}.
	 * @param ctx the parse tree
	 */
	void enterVoidInterfaceMethodDeclaratorRest(JavaLRParser.VoidInterfaceMethodDeclaratorRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#voidInterfaceMethodDeclaratorRest}.
	 * @param ctx the parse tree
	 */
	void exitVoidInterfaceMethodDeclaratorRest(JavaLRParser.VoidInterfaceMethodDeclaratorRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#constructorDeclaratorRest}.
	 * @param ctx the parse tree
	 */
	void enterConstructorDeclaratorRest(JavaLRParser.ConstructorDeclaratorRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#constructorDeclaratorRest}.
	 * @param ctx the parse tree
	 */
	void exitConstructorDeclaratorRest(JavaLRParser.ConstructorDeclaratorRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#constantDeclarator}.
	 * @param ctx the parse tree
	 */
	void enterConstantDeclarator(JavaLRParser.ConstantDeclaratorContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#constantDeclarator}.
	 * @param ctx the parse tree
	 */
	void exitConstantDeclarator(JavaLRParser.ConstantDeclaratorContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#variableDeclarators}.
	 * @param ctx the parse tree
	 */
	void enterVariableDeclarators(JavaLRParser.VariableDeclaratorsContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#variableDeclarators}.
	 * @param ctx the parse tree
	 */
	void exitVariableDeclarators(JavaLRParser.VariableDeclaratorsContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#variableDeclarator}.
	 * @param ctx the parse tree
	 */
	void enterVariableDeclarator(JavaLRParser.VariableDeclaratorContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#variableDeclarator}.
	 * @param ctx the parse tree
	 */
	void exitVariableDeclarator(JavaLRParser.VariableDeclaratorContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#constantDeclaratorsRest}.
	 * @param ctx the parse tree
	 */
	void enterConstantDeclaratorsRest(JavaLRParser.ConstantDeclaratorsRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#constantDeclaratorsRest}.
	 * @param ctx the parse tree
	 */
	void exitConstantDeclaratorsRest(JavaLRParser.ConstantDeclaratorsRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#constantDeclaratorRest}.
	 * @param ctx the parse tree
	 */
	void enterConstantDeclaratorRest(JavaLRParser.ConstantDeclaratorRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#constantDeclaratorRest}.
	 * @param ctx the parse tree
	 */
	void exitConstantDeclaratorRest(JavaLRParser.ConstantDeclaratorRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#variableDeclaratorId}.
	 * @param ctx the parse tree
	 */
	void enterVariableDeclaratorId(JavaLRParser.VariableDeclaratorIdContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#variableDeclaratorId}.
	 * @param ctx the parse tree
	 */
	void exitVariableDeclaratorId(JavaLRParser.VariableDeclaratorIdContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#variableInitializer}.
	 * @param ctx the parse tree
	 */
	void enterVariableInitializer(JavaLRParser.VariableInitializerContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#variableInitializer}.
	 * @param ctx the parse tree
	 */
	void exitVariableInitializer(JavaLRParser.VariableInitializerContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#arrayInitializer}.
	 * @param ctx the parse tree
	 */
	void enterArrayInitializer(JavaLRParser.ArrayInitializerContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#arrayInitializer}.
	 * @param ctx the parse tree
	 */
	void exitArrayInitializer(JavaLRParser.ArrayInitializerContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#modifier}.
	 * @param ctx the parse tree
	 */
	void enterModifier(JavaLRParser.ModifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#modifier}.
	 * @param ctx the parse tree
	 */
	void exitModifier(JavaLRParser.ModifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#packageOrTypeName}.
	 * @param ctx the parse tree
	 */
	void enterPackageOrTypeName(JavaLRParser.PackageOrTypeNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#packageOrTypeName}.
	 * @param ctx the parse tree
	 */
	void exitPackageOrTypeName(JavaLRParser.PackageOrTypeNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#enumConstantName}.
	 * @param ctx the parse tree
	 */
	void enterEnumConstantName(JavaLRParser.EnumConstantNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#enumConstantName}.
	 * @param ctx the parse tree
	 */
	void exitEnumConstantName(JavaLRParser.EnumConstantNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#typeName}.
	 * @param ctx the parse tree
	 */
	void enterTypeName(JavaLRParser.TypeNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#typeName}.
	 * @param ctx the parse tree
	 */
	void exitTypeName(JavaLRParser.TypeNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#type}.
	 * @param ctx the parse tree
	 */
	void enterType(JavaLRParser.TypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#type}.
	 * @param ctx the parse tree
	 */
	void exitType(JavaLRParser.TypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#classOrInterfaceType}.
	 * @param ctx the parse tree
	 */
	void enterClassOrInterfaceType(JavaLRParser.ClassOrInterfaceTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#classOrInterfaceType}.
	 * @param ctx the parse tree
	 */
	void exitClassOrInterfaceType(JavaLRParser.ClassOrInterfaceTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void enterPrimitiveType(JavaLRParser.PrimitiveTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void exitPrimitiveType(JavaLRParser.PrimitiveTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#variableModifier}.
	 * @param ctx the parse tree
	 */
	void enterVariableModifier(JavaLRParser.VariableModifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#variableModifier}.
	 * @param ctx the parse tree
	 */
	void exitVariableModifier(JavaLRParser.VariableModifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#typeArguments}.
	 * @param ctx the parse tree
	 */
	void enterTypeArguments(JavaLRParser.TypeArgumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#typeArguments}.
	 * @param ctx the parse tree
	 */
	void exitTypeArguments(JavaLRParser.TypeArgumentsContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#typeArgument}.
	 * @param ctx the parse tree
	 */
	void enterTypeArgument(JavaLRParser.TypeArgumentContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#typeArgument}.
	 * @param ctx the parse tree
	 */
	void exitTypeArgument(JavaLRParser.TypeArgumentContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#qualifiedNameList}.
	 * @param ctx the parse tree
	 */
	void enterQualifiedNameList(JavaLRParser.QualifiedNameListContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#qualifiedNameList}.
	 * @param ctx the parse tree
	 */
	void exitQualifiedNameList(JavaLRParser.QualifiedNameListContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#formalParameters}.
	 * @param ctx the parse tree
	 */
	void enterFormalParameters(JavaLRParser.FormalParametersContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#formalParameters}.
	 * @param ctx the parse tree
	 */
	void exitFormalParameters(JavaLRParser.FormalParametersContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#formalParameterDecls}.
	 * @param ctx the parse tree
	 */
	void enterFormalParameterDecls(JavaLRParser.FormalParameterDeclsContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#formalParameterDecls}.
	 * @param ctx the parse tree
	 */
	void exitFormalParameterDecls(JavaLRParser.FormalParameterDeclsContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#formalParameterDeclsRest}.
	 * @param ctx the parse tree
	 */
	void enterFormalParameterDeclsRest(JavaLRParser.FormalParameterDeclsRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#formalParameterDeclsRest}.
	 * @param ctx the parse tree
	 */
	void exitFormalParameterDeclsRest(JavaLRParser.FormalParameterDeclsRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#methodBody}.
	 * @param ctx the parse tree
	 */
	void enterMethodBody(JavaLRParser.MethodBodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#methodBody}.
	 * @param ctx the parse tree
	 */
	void exitMethodBody(JavaLRParser.MethodBodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#constructorBody}.
	 * @param ctx the parse tree
	 */
	void enterConstructorBody(JavaLRParser.ConstructorBodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#constructorBody}.
	 * @param ctx the parse tree
	 */
	void exitConstructorBody(JavaLRParser.ConstructorBodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#qualifiedName}.
	 * @param ctx the parse tree
	 */
	void enterQualifiedName(JavaLRParser.QualifiedNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#qualifiedName}.
	 * @param ctx the parse tree
	 */
	void exitQualifiedName(JavaLRParser.QualifiedNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(JavaLRParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(JavaLRParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#annotations}.
	 * @param ctx the parse tree
	 */
	void enterAnnotations(JavaLRParser.AnnotationsContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#annotations}.
	 * @param ctx the parse tree
	 */
	void exitAnnotations(JavaLRParser.AnnotationsContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#annotation}.
	 * @param ctx the parse tree
	 */
	void enterAnnotation(JavaLRParser.AnnotationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#annotation}.
	 * @param ctx the parse tree
	 */
	void exitAnnotation(JavaLRParser.AnnotationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#annotationName}.
	 * @param ctx the parse tree
	 */
	void enterAnnotationName(JavaLRParser.AnnotationNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#annotationName}.
	 * @param ctx the parse tree
	 */
	void exitAnnotationName(JavaLRParser.AnnotationNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#elementValuePairs}.
	 * @param ctx the parse tree
	 */
	void enterElementValuePairs(JavaLRParser.ElementValuePairsContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#elementValuePairs}.
	 * @param ctx the parse tree
	 */
	void exitElementValuePairs(JavaLRParser.ElementValuePairsContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#elementValuePair}.
	 * @param ctx the parse tree
	 */
	void enterElementValuePair(JavaLRParser.ElementValuePairContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#elementValuePair}.
	 * @param ctx the parse tree
	 */
	void exitElementValuePair(JavaLRParser.ElementValuePairContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#elementValue}.
	 * @param ctx the parse tree
	 */
	void enterElementValue(JavaLRParser.ElementValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#elementValue}.
	 * @param ctx the parse tree
	 */
	void exitElementValue(JavaLRParser.ElementValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#elementValueArrayInitializer}.
	 * @param ctx the parse tree
	 */
	void enterElementValueArrayInitializer(JavaLRParser.ElementValueArrayInitializerContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#elementValueArrayInitializer}.
	 * @param ctx the parse tree
	 */
	void exitElementValueArrayInitializer(JavaLRParser.ElementValueArrayInitializerContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#annotationTypeDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterAnnotationTypeDeclaration(JavaLRParser.AnnotationTypeDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#annotationTypeDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitAnnotationTypeDeclaration(JavaLRParser.AnnotationTypeDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#annotationTypeBody}.
	 * @param ctx the parse tree
	 */
	void enterAnnotationTypeBody(JavaLRParser.AnnotationTypeBodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#annotationTypeBody}.
	 * @param ctx the parse tree
	 */
	void exitAnnotationTypeBody(JavaLRParser.AnnotationTypeBodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#annotationTypeElementDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterAnnotationTypeElementDeclaration(JavaLRParser.AnnotationTypeElementDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#annotationTypeElementDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitAnnotationTypeElementDeclaration(JavaLRParser.AnnotationTypeElementDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#annotationTypeElementRest}.
	 * @param ctx the parse tree
	 */
	void enterAnnotationTypeElementRest(JavaLRParser.AnnotationTypeElementRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#annotationTypeElementRest}.
	 * @param ctx the parse tree
	 */
	void exitAnnotationTypeElementRest(JavaLRParser.AnnotationTypeElementRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#annotationMethodOrConstantRest}.
	 * @param ctx the parse tree
	 */
	void enterAnnotationMethodOrConstantRest(JavaLRParser.AnnotationMethodOrConstantRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#annotationMethodOrConstantRest}.
	 * @param ctx the parse tree
	 */
	void exitAnnotationMethodOrConstantRest(JavaLRParser.AnnotationMethodOrConstantRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#annotationMethodRest}.
	 * @param ctx the parse tree
	 */
	void enterAnnotationMethodRest(JavaLRParser.AnnotationMethodRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#annotationMethodRest}.
	 * @param ctx the parse tree
	 */
	void exitAnnotationMethodRest(JavaLRParser.AnnotationMethodRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#annotationConstantRest}.
	 * @param ctx the parse tree
	 */
	void enterAnnotationConstantRest(JavaLRParser.AnnotationConstantRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#annotationConstantRest}.
	 * @param ctx the parse tree
	 */
	void exitAnnotationConstantRest(JavaLRParser.AnnotationConstantRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#defaultValue}.
	 * @param ctx the parse tree
	 */
	void enterDefaultValue(JavaLRParser.DefaultValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#defaultValue}.
	 * @param ctx the parse tree
	 */
	void exitDefaultValue(JavaLRParser.DefaultValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(JavaLRParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(JavaLRParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#blockStatement}.
	 * @param ctx the parse tree
	 */
	void enterBlockStatement(JavaLRParser.BlockStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#blockStatement}.
	 * @param ctx the parse tree
	 */
	void exitBlockStatement(JavaLRParser.BlockStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#localVariableDeclarationStatement}.
	 * @param ctx the parse tree
	 */
	void enterLocalVariableDeclarationStatement(JavaLRParser.LocalVariableDeclarationStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#localVariableDeclarationStatement}.
	 * @param ctx the parse tree
	 */
	void exitLocalVariableDeclarationStatement(JavaLRParser.LocalVariableDeclarationStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#localVariableDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterLocalVariableDeclaration(JavaLRParser.LocalVariableDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#localVariableDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitLocalVariableDeclaration(JavaLRParser.LocalVariableDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#variableModifiers}.
	 * @param ctx the parse tree
	 */
	void enterVariableModifiers(JavaLRParser.VariableModifiersContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#variableModifiers}.
	 * @param ctx the parse tree
	 */
	void exitVariableModifiers(JavaLRParser.VariableModifiersContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(JavaLRParser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(JavaLRParser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#catches}.
	 * @param ctx the parse tree
	 */
	void enterCatches(JavaLRParser.CatchesContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#catches}.
	 * @param ctx the parse tree
	 */
	void exitCatches(JavaLRParser.CatchesContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#catchClause}.
	 * @param ctx the parse tree
	 */
	void enterCatchClause(JavaLRParser.CatchClauseContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#catchClause}.
	 * @param ctx the parse tree
	 */
	void exitCatchClause(JavaLRParser.CatchClauseContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#catchType}.
	 * @param ctx the parse tree
	 */
	void enterCatchType(JavaLRParser.CatchTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#catchType}.
	 * @param ctx the parse tree
	 */
	void exitCatchType(JavaLRParser.CatchTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#finallyBlock}.
	 * @param ctx the parse tree
	 */
	void enterFinallyBlock(JavaLRParser.FinallyBlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#finallyBlock}.
	 * @param ctx the parse tree
	 */
	void exitFinallyBlock(JavaLRParser.FinallyBlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#resourceSpecification}.
	 * @param ctx the parse tree
	 */
	void enterResourceSpecification(JavaLRParser.ResourceSpecificationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#resourceSpecification}.
	 * @param ctx the parse tree
	 */
	void exitResourceSpecification(JavaLRParser.ResourceSpecificationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#resources}.
	 * @param ctx the parse tree
	 */
	void enterResources(JavaLRParser.ResourcesContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#resources}.
	 * @param ctx the parse tree
	 */
	void exitResources(JavaLRParser.ResourcesContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#resource}.
	 * @param ctx the parse tree
	 */
	void enterResource(JavaLRParser.ResourceContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#resource}.
	 * @param ctx the parse tree
	 */
	void exitResource(JavaLRParser.ResourceContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#formalParameter}.
	 * @param ctx the parse tree
	 */
	void enterFormalParameter(JavaLRParser.FormalParameterContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#formalParameter}.
	 * @param ctx the parse tree
	 */
	void exitFormalParameter(JavaLRParser.FormalParameterContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#switchBlockStatementGroups}.
	 * @param ctx the parse tree
	 */
	void enterSwitchBlockStatementGroups(JavaLRParser.SwitchBlockStatementGroupsContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#switchBlockStatementGroups}.
	 * @param ctx the parse tree
	 */
	void exitSwitchBlockStatementGroups(JavaLRParser.SwitchBlockStatementGroupsContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#switchBlockStatementGroup}.
	 * @param ctx the parse tree
	 */
	void enterSwitchBlockStatementGroup(JavaLRParser.SwitchBlockStatementGroupContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#switchBlockStatementGroup}.
	 * @param ctx the parse tree
	 */
	void exitSwitchBlockStatementGroup(JavaLRParser.SwitchBlockStatementGroupContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#switchLabel}.
	 * @param ctx the parse tree
	 */
	void enterSwitchLabel(JavaLRParser.SwitchLabelContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#switchLabel}.
	 * @param ctx the parse tree
	 */
	void exitSwitchLabel(JavaLRParser.SwitchLabelContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#forControl}.
	 * @param ctx the parse tree
	 */
	void enterForControl(JavaLRParser.ForControlContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#forControl}.
	 * @param ctx the parse tree
	 */
	void exitForControl(JavaLRParser.ForControlContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#forInit}.
	 * @param ctx the parse tree
	 */
	void enterForInit(JavaLRParser.ForInitContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#forInit}.
	 * @param ctx the parse tree
	 */
	void exitForInit(JavaLRParser.ForInitContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#enhancedForControl}.
	 * @param ctx the parse tree
	 */
	void enterEnhancedForControl(JavaLRParser.EnhancedForControlContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#enhancedForControl}.
	 * @param ctx the parse tree
	 */
	void exitEnhancedForControl(JavaLRParser.EnhancedForControlContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#forUpdate}.
	 * @param ctx the parse tree
	 */
	void enterForUpdate(JavaLRParser.ForUpdateContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#forUpdate}.
	 * @param ctx the parse tree
	 */
	void exitForUpdate(JavaLRParser.ForUpdateContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#parExpression}.
	 * @param ctx the parse tree
	 */
	void enterParExpression(JavaLRParser.ParExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#parExpression}.
	 * @param ctx the parse tree
	 */
	void exitParExpression(JavaLRParser.ParExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(JavaLRParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(JavaLRParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#statementExpression}.
	 * @param ctx the parse tree
	 */
	void enterStatementExpression(JavaLRParser.StatementExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#statementExpression}.
	 * @param ctx the parse tree
	 */
	void exitStatementExpression(JavaLRParser.StatementExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#constantExpression}.
	 * @param ctx the parse tree
	 */
	void enterConstantExpression(JavaLRParser.ConstantExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#constantExpression}.
	 * @param ctx the parse tree
	 */
	void exitConstantExpression(JavaLRParser.ConstantExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(JavaLRParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(JavaLRParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#primary}.
	 * @param ctx the parse tree
	 */
	void enterPrimary(JavaLRParser.PrimaryContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#primary}.
	 * @param ctx the parse tree
	 */
	void exitPrimary(JavaLRParser.PrimaryContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#creator}.
	 * @param ctx the parse tree
	 */
	void enterCreator(JavaLRParser.CreatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#creator}.
	 * @param ctx the parse tree
	 */
	void exitCreator(JavaLRParser.CreatorContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#createdName}.
	 * @param ctx the parse tree
	 */
	void enterCreatedName(JavaLRParser.CreatedNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#createdName}.
	 * @param ctx the parse tree
	 */
	void exitCreatedName(JavaLRParser.CreatedNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#innerCreator}.
	 * @param ctx the parse tree
	 */
	void enterInnerCreator(JavaLRParser.InnerCreatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#innerCreator}.
	 * @param ctx the parse tree
	 */
	void exitInnerCreator(JavaLRParser.InnerCreatorContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#arrayCreatorRest}.
	 * @param ctx the parse tree
	 */
	void enterArrayCreatorRest(JavaLRParser.ArrayCreatorRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#arrayCreatorRest}.
	 * @param ctx the parse tree
	 */
	void exitArrayCreatorRest(JavaLRParser.ArrayCreatorRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#classCreatorRest}.
	 * @param ctx the parse tree
	 */
	void enterClassCreatorRest(JavaLRParser.ClassCreatorRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#classCreatorRest}.
	 * @param ctx the parse tree
	 */
	void exitClassCreatorRest(JavaLRParser.ClassCreatorRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#explicitGenericInvocation}.
	 * @param ctx the parse tree
	 */
	void enterExplicitGenericInvocation(JavaLRParser.ExplicitGenericInvocationContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#explicitGenericInvocation}.
	 * @param ctx the parse tree
	 */
	void exitExplicitGenericInvocation(JavaLRParser.ExplicitGenericInvocationContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#nonWildcardTypeArguments}.
	 * @param ctx the parse tree
	 */
	void enterNonWildcardTypeArguments(JavaLRParser.NonWildcardTypeArgumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#nonWildcardTypeArguments}.
	 * @param ctx the parse tree
	 */
	void exitNonWildcardTypeArguments(JavaLRParser.NonWildcardTypeArgumentsContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#typeArgumentsOrDiamond}.
	 * @param ctx the parse tree
	 */
	void enterTypeArgumentsOrDiamond(JavaLRParser.TypeArgumentsOrDiamondContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#typeArgumentsOrDiamond}.
	 * @param ctx the parse tree
	 */
	void exitTypeArgumentsOrDiamond(JavaLRParser.TypeArgumentsOrDiamondContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#nonWildcardTypeArgumentsOrDiamond}.
	 * @param ctx the parse tree
	 */
	void enterNonWildcardTypeArgumentsOrDiamond(JavaLRParser.NonWildcardTypeArgumentsOrDiamondContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#nonWildcardTypeArgumentsOrDiamond}.
	 * @param ctx the parse tree
	 */
	void exitNonWildcardTypeArgumentsOrDiamond(JavaLRParser.NonWildcardTypeArgumentsOrDiamondContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#superSuffix}.
	 * @param ctx the parse tree
	 */
	void enterSuperSuffix(JavaLRParser.SuperSuffixContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#superSuffix}.
	 * @param ctx the parse tree
	 */
	void exitSuperSuffix(JavaLRParser.SuperSuffixContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#explicitGenericInvocationSuffix}.
	 * @param ctx the parse tree
	 */
	void enterExplicitGenericInvocationSuffix(JavaLRParser.ExplicitGenericInvocationSuffixContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#explicitGenericInvocationSuffix}.
	 * @param ctx the parse tree
	 */
	void exitExplicitGenericInvocationSuffix(JavaLRParser.ExplicitGenericInvocationSuffixContext ctx);
	/**
	 * Enter a parse tree produced by {@link JavaLRParser#arguments}.
	 * @param ctx the parse tree
	 */
	void enterArguments(JavaLRParser.ArgumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link JavaLRParser#arguments}.
	 * @param ctx the parse tree
	 */
	void exitArguments(JavaLRParser.ArgumentsContext ctx);
}