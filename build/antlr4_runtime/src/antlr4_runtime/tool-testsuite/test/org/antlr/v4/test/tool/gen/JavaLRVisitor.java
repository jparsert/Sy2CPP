// Generated from /home/julian/coding/Sy2CPP/build/antlr4_runtime/src/antlr4_runtime/tool-testsuite/test/org/antlr/v4/test/tool/JavaLR.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link JavaLRParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface JavaLRVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#compilationUnit}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCompilationUnit(JavaLRParser.CompilationUnitContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#packageDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPackageDeclaration(JavaLRParser.PackageDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#importDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitImportDeclaration(JavaLRParser.ImportDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#typeDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeDeclaration(JavaLRParser.TypeDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#classOrInterfaceDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitClassOrInterfaceDeclaration(JavaLRParser.ClassOrInterfaceDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#classOrInterfaceModifiers}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitClassOrInterfaceModifiers(JavaLRParser.ClassOrInterfaceModifiersContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#classOrInterfaceModifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitClassOrInterfaceModifier(JavaLRParser.ClassOrInterfaceModifierContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#modifiers}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitModifiers(JavaLRParser.ModifiersContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#classDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitClassDeclaration(JavaLRParser.ClassDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#normalClassDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNormalClassDeclaration(JavaLRParser.NormalClassDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#typeParameters}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeParameters(JavaLRParser.TypeParametersContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#typeParameter}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeParameter(JavaLRParser.TypeParameterContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#typeBound}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeBound(JavaLRParser.TypeBoundContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#enumDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnumDeclaration(JavaLRParser.EnumDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#enumBody}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnumBody(JavaLRParser.EnumBodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#enumConstants}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnumConstants(JavaLRParser.EnumConstantsContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#enumConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnumConstant(JavaLRParser.EnumConstantContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#enumBodyDeclarations}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnumBodyDeclarations(JavaLRParser.EnumBodyDeclarationsContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#interfaceDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInterfaceDeclaration(JavaLRParser.InterfaceDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#normalInterfaceDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNormalInterfaceDeclaration(JavaLRParser.NormalInterfaceDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#typeList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeList(JavaLRParser.TypeListContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#classBody}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitClassBody(JavaLRParser.ClassBodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#interfaceBody}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInterfaceBody(JavaLRParser.InterfaceBodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#classBodyDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitClassBodyDeclaration(JavaLRParser.ClassBodyDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#memberDecl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMemberDecl(JavaLRParser.MemberDeclContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#memberDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMemberDeclaration(JavaLRParser.MemberDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#genericMethodOrConstructorDecl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGenericMethodOrConstructorDecl(JavaLRParser.GenericMethodOrConstructorDeclContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#genericMethodOrConstructorRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGenericMethodOrConstructorRest(JavaLRParser.GenericMethodOrConstructorRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#methodDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMethodDeclaration(JavaLRParser.MethodDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#fieldDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFieldDeclaration(JavaLRParser.FieldDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#interfaceBodyDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInterfaceBodyDeclaration(JavaLRParser.InterfaceBodyDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#interfaceMemberDecl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInterfaceMemberDecl(JavaLRParser.InterfaceMemberDeclContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#interfaceMethodOrFieldDecl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInterfaceMethodOrFieldDecl(JavaLRParser.InterfaceMethodOrFieldDeclContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#interfaceMethodOrFieldRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInterfaceMethodOrFieldRest(JavaLRParser.InterfaceMethodOrFieldRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#methodDeclaratorRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMethodDeclaratorRest(JavaLRParser.MethodDeclaratorRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#voidMethodDeclaratorRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVoidMethodDeclaratorRest(JavaLRParser.VoidMethodDeclaratorRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#interfaceMethodDeclaratorRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInterfaceMethodDeclaratorRest(JavaLRParser.InterfaceMethodDeclaratorRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#interfaceGenericMethodDecl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInterfaceGenericMethodDecl(JavaLRParser.InterfaceGenericMethodDeclContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#voidInterfaceMethodDeclaratorRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVoidInterfaceMethodDeclaratorRest(JavaLRParser.VoidInterfaceMethodDeclaratorRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#constructorDeclaratorRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstructorDeclaratorRest(JavaLRParser.ConstructorDeclaratorRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#constantDeclarator}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstantDeclarator(JavaLRParser.ConstantDeclaratorContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#variableDeclarators}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableDeclarators(JavaLRParser.VariableDeclaratorsContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#variableDeclarator}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableDeclarator(JavaLRParser.VariableDeclaratorContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#constantDeclaratorsRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstantDeclaratorsRest(JavaLRParser.ConstantDeclaratorsRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#constantDeclaratorRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstantDeclaratorRest(JavaLRParser.ConstantDeclaratorRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#variableDeclaratorId}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableDeclaratorId(JavaLRParser.VariableDeclaratorIdContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#variableInitializer}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableInitializer(JavaLRParser.VariableInitializerContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#arrayInitializer}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArrayInitializer(JavaLRParser.ArrayInitializerContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#modifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitModifier(JavaLRParser.ModifierContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#packageOrTypeName}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPackageOrTypeName(JavaLRParser.PackageOrTypeNameContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#enumConstantName}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnumConstantName(JavaLRParser.EnumConstantNameContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#typeName}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeName(JavaLRParser.TypeNameContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#type}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType(JavaLRParser.TypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#classOrInterfaceType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitClassOrInterfaceType(JavaLRParser.ClassOrInterfaceTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#primitiveType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPrimitiveType(JavaLRParser.PrimitiveTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#variableModifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableModifier(JavaLRParser.VariableModifierContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#typeArguments}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeArguments(JavaLRParser.TypeArgumentsContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#typeArgument}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeArgument(JavaLRParser.TypeArgumentContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#qualifiedNameList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitQualifiedNameList(JavaLRParser.QualifiedNameListContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#formalParameters}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFormalParameters(JavaLRParser.FormalParametersContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#formalParameterDecls}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFormalParameterDecls(JavaLRParser.FormalParameterDeclsContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#formalParameterDeclsRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFormalParameterDeclsRest(JavaLRParser.FormalParameterDeclsRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#methodBody}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMethodBody(JavaLRParser.MethodBodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#constructorBody}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstructorBody(JavaLRParser.ConstructorBodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#qualifiedName}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitQualifiedName(JavaLRParser.QualifiedNameContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#literal}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLiteral(JavaLRParser.LiteralContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#annotations}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnnotations(JavaLRParser.AnnotationsContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#annotation}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnnotation(JavaLRParser.AnnotationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#annotationName}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnnotationName(JavaLRParser.AnnotationNameContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#elementValuePairs}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitElementValuePairs(JavaLRParser.ElementValuePairsContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#elementValuePair}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitElementValuePair(JavaLRParser.ElementValuePairContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#elementValue}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitElementValue(JavaLRParser.ElementValueContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#elementValueArrayInitializer}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitElementValueArrayInitializer(JavaLRParser.ElementValueArrayInitializerContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#annotationTypeDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnnotationTypeDeclaration(JavaLRParser.AnnotationTypeDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#annotationTypeBody}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnnotationTypeBody(JavaLRParser.AnnotationTypeBodyContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#annotationTypeElementDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnnotationTypeElementDeclaration(JavaLRParser.AnnotationTypeElementDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#annotationTypeElementRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnnotationTypeElementRest(JavaLRParser.AnnotationTypeElementRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#annotationMethodOrConstantRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnnotationMethodOrConstantRest(JavaLRParser.AnnotationMethodOrConstantRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#annotationMethodRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnnotationMethodRest(JavaLRParser.AnnotationMethodRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#annotationConstantRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnnotationConstantRest(JavaLRParser.AnnotationConstantRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#defaultValue}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDefaultValue(JavaLRParser.DefaultValueContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#block}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBlock(JavaLRParser.BlockContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#blockStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBlockStatement(JavaLRParser.BlockStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#localVariableDeclarationStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLocalVariableDeclarationStatement(JavaLRParser.LocalVariableDeclarationStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#localVariableDeclaration}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLocalVariableDeclaration(JavaLRParser.LocalVariableDeclarationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#variableModifiers}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableModifiers(JavaLRParser.VariableModifiersContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#statement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStatement(JavaLRParser.StatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#catches}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCatches(JavaLRParser.CatchesContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#catchClause}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCatchClause(JavaLRParser.CatchClauseContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#catchType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCatchType(JavaLRParser.CatchTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#finallyBlock}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFinallyBlock(JavaLRParser.FinallyBlockContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#resourceSpecification}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitResourceSpecification(JavaLRParser.ResourceSpecificationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#resources}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitResources(JavaLRParser.ResourcesContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#resource}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitResource(JavaLRParser.ResourceContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#formalParameter}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFormalParameter(JavaLRParser.FormalParameterContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#switchBlockStatementGroups}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSwitchBlockStatementGroups(JavaLRParser.SwitchBlockStatementGroupsContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#switchBlockStatementGroup}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSwitchBlockStatementGroup(JavaLRParser.SwitchBlockStatementGroupContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#switchLabel}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSwitchLabel(JavaLRParser.SwitchLabelContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#forControl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitForControl(JavaLRParser.ForControlContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#forInit}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitForInit(JavaLRParser.ForInitContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#enhancedForControl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnhancedForControl(JavaLRParser.EnhancedForControlContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#forUpdate}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitForUpdate(JavaLRParser.ForUpdateContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#parExpression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParExpression(JavaLRParser.ParExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#expressionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpressionList(JavaLRParser.ExpressionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#statementExpression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStatementExpression(JavaLRParser.StatementExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#constantExpression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstantExpression(JavaLRParser.ConstantExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(JavaLRParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#primary}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPrimary(JavaLRParser.PrimaryContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#creator}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCreator(JavaLRParser.CreatorContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#createdName}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCreatedName(JavaLRParser.CreatedNameContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#innerCreator}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInnerCreator(JavaLRParser.InnerCreatorContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#arrayCreatorRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArrayCreatorRest(JavaLRParser.ArrayCreatorRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#classCreatorRest}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitClassCreatorRest(JavaLRParser.ClassCreatorRestContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#explicitGenericInvocation}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExplicitGenericInvocation(JavaLRParser.ExplicitGenericInvocationContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#nonWildcardTypeArguments}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNonWildcardTypeArguments(JavaLRParser.NonWildcardTypeArgumentsContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#typeArgumentsOrDiamond}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeArgumentsOrDiamond(JavaLRParser.TypeArgumentsOrDiamondContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#nonWildcardTypeArgumentsOrDiamond}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNonWildcardTypeArgumentsOrDiamond(JavaLRParser.NonWildcardTypeArgumentsOrDiamondContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#superSuffix}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSuperSuffix(JavaLRParser.SuperSuffixContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#explicitGenericInvocationSuffix}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExplicitGenericInvocationSuffix(JavaLRParser.ExplicitGenericInvocationSuffixContext ctx);
	/**
	 * Visit a parse tree produced by {@link JavaLRParser#arguments}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArguments(JavaLRParser.ArgumentsContext ctx);
}