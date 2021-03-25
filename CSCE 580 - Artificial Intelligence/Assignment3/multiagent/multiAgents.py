# multiAgents.py
# --------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


from util import manhattanDistance
from game import Directions
import random, util

from game import Agent

class ReflexAgent(Agent):
    """
    A reflex agent chooses an action at each choice point by examining
    its alternatives via a state evaluation function.

    The code below is provided as a guide.  You are welcome to change
    it in any way you see fit, so long as you don't touch our method
    headers.
    """


    def getAction(self, gameState):
        """
        You do not need to change this method, but you're welcome to.

        getAction chooses among the best options according to the evaluation function.

        Just like in the previous project, getAction takes a GameState and returns
        some Directions.X for some X in the set {NORTH, SOUTH, WEST, EAST, STOP}
        """
        # Collect legal moves and successor states
        legalMoves = gameState.getLegalActions()

        # Choose one of the best actions
        scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
        bestScore = max(scores)
        bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
        chosenIndex = random.choice(bestIndices) # Pick randomly among the best

        "Add more of your code here if you want to"

        return legalMoves[chosenIndex]

    def evaluationFunction(self, currentGameState, action):
        """
        Design a better evaluation function here.

        The evaluation function takes in the current and proposed successor
        GameStates (pacman.py) and returns a number, where higher numbers are better.

        The code below extracts some useful information from the state, like the
        remaining food (newFood) and Pacman position after moving (newPos).
        newScaredTimes holds the number of moves that each ghost will remain
        scared because of Pacman having eaten a power pellet.

        Print out these variables to see what you're getting, then combine them
        to create a masterful evaluation function.
        """
        # Useful information you can extract from a GameState (pacman.py)
        successorGameState = currentGameState.generatePacmanSuccessor(action)
        newPos = successorGameState.getPacmanPosition()
        newFood = successorGameState.getFood()
        newGhostStates = successorGameState.getGhostStates()
        newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]

        score=0.0
        ghostPositions = successorGameState.getGhostPositions()
        
        for ghost in ghostPositions:
            if manhattanDistance(newPos, ghost) <= 2:
                score = score -1000
        
        
        currentFood = currentGameState.getFood().asList()
        currentPos = currentGameState.getPacmanPosition()
        
        index = 0
        minDistance = manhattanDistance(currentPos, currentFood[index])
        
        for i in range(len(currentFood)):
            temp = manhattanDistance(currentPos,currentFood[i])
            if temp<minDistance:
                minDistance = temp
                index = i
         
        if manhattanDistance(newPos, currentFood[index])<minDistance:
            score = score + 100
        return score + successorGameState.getScore()
        
        
		#return successorGameState.getScore()

def scoreEvaluationFunction(currentGameState):
    """
    This default evaluation function just returns the score of the state.
    The score is the same one displayed in the Pacman GUI.

    This evaluation function is meant for use with adversarial search agents
    (not reflex agents).
    """
    return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
    """
    This class provides some common elements to all of your
    multi-agent searchers.  Any methods defined here will be available
    to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

    You *do not* need to make any changes here, but you can if you want to
    add functionality to all your adversarial search agents.  Please do not
    remove anything, however.

    Note: this is an abstract class: one that should not be instantiated.  It's
    only partially specified, and designed to be extended.  Agent (game.py)
    is another abstract class.
    """

    def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
        self.index = 0 # Pacman is always agent index 0
        self.evaluationFunction = util.lookup(evalFn, globals())
        self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
    """
    Your minimax agent (question 2)
    """

    def getAction(self, gameState):
        """
        Returns the minimax action from the current gameState using self.depth
        and self.evaluationFunction.

        Here are some method calls that might be useful when implementing minimax.

        gameState.getLegalActions(agentIndex):
        Returns a list of legal actions for an agent
        agentIndex=0 means Pacman, ghosts are >= 1

        gameState.generateSuccessor(agentIndex, action):
        Returns the successor game state after an agent takes an action

        gameState.getNumAgents():
        Returns the total number of agents in the game

        gameState.isWin():
        Returns whether or not the game state is a winning state

        gameState.isLose():
        Returns whether or not the game state is a losing state
        """
        def value(gameState, agentIndex, depth, agentsNum):
            if gameState.isWin() or gameState.isLose() or depth > self.depth:
                return self.evaluationFunction(gameState)
            if agentIndex == 0:
                
                return max_value(gameState, agentIndex, depth, agentsNum)
            else :
                return min_value(gameState, agentIndex, depth, agentsNum)
        def max_value(gameState, agentIndex, depth, agentsNum):
            v = float("-inf")
            actions = gameState.getLegalActions(agentIndex)
            if depth ==1:
                bestAction=random.choice(actions)
                
                successorStates = [(action,gameState.generateSuccessor(agentIndex, action)) for action in actions]
                
                for state in successorStates:
                    tempV = value(state[1], agentIndex+1, depth, agentsNum)
                    if tempV>v:
                        v=tempV
                        bestAction = state[0]
                return bestAction
            else:
                successorStates = [gameState.generateSuccessor(agentIndex, action) for action in actions]
                for state in successorStates:
                    v=max(v,value(state, agentIndex+1, depth, agentsNum))
                return v
        def min_value(gameState, agentIndex, depth, agentsNum):
            v = float("inf")
            actions = gameState.getLegalActions(agentIndex)
            successorStates = [gameState.generateSuccessor(agentIndex, action) for action in actions]
            for state in successorStates:
                if agentIndex >= agentsNum-1:
                    v=min(v,value(state, 0, depth+1, agentsNum))
                else :
                    v=min(v,value(state, agentIndex+1, depth, agentsNum))
            return v
        
        return max_value(gameState, 0, 1, gameState.getNumAgents())

class AlphaBetaAgent(MultiAgentSearchAgent):
    """
    Your minimax agent with alpha-beta pruning (question 3)
    """

    def getAction(self, gameState):
        """
        Returns the minimax action using self.depth and self.evaluationFunction
        """
        def value(gameState, alpha, beta, agentIndex, depth):
            if gameState.isWin() or gameState.isLose() or depth >= self.depth*agentsNum:
                return self.evaluationFunction(gameState)
            if agentIndex == 0:
                
                return max_value(gameState, alpha, beta, agentIndex, depth)
            else :
                return min_value(gameState, alpha, beta, agentIndex, depth)
        def max_value(gameState, alpha, beta, agentIndex, depth):
            v = float("-inf")
            actions = gameState.getLegalActions(agentIndex)
            if depth ==0:
                bestAction=random.choice(actions)
                
                
                for action in actions:
                    successorState = (action,gameState.generateSuccessor(agentIndex, action))
                
                    tempV = value(successorState[1], alpha, beta, (depth+1)%agentsNum, depth+1)
                    if tempV>v:
                        v=tempV
                        bestAction = successorState[0]
                    if v > beta:
                        return bestAction
                    alpha = max(alpha,v)
                return bestAction
            else:
                for action in actions:
                    successorState = gameState.generateSuccessor(agentIndex, action)
                
                    v=max(v,value(successorState, alpha, beta, (depth+1)%agentsNum, depth+1))
                    if v > beta:
                        return v
                    alpha = max(alpha,v)
                return v
        def min_value(gameState, alpha, beta, agentIndex, depth):
            v = float("inf")
            actions = gameState.getLegalActions(agentIndex)
            
            for action in actions:
                successorState = gameState.generateSuccessor(agentIndex, action)
                v=min(v,value(successorState, alpha, beta, (depth+1)% agentsNum, depth+1))
                if v < alpha:
                    return v
                beta = min(beta,v)
            return v
        alpha=float("-inf")
        beta=float("inf")
        agentsNum = gameState.getNumAgents()
        return max_value(gameState, alpha, beta, 0, 0)

class ExpectimaxAgent(MultiAgentSearchAgent):
    """
      Your expectimax agent (question 4)
    """

    def getAction(self, gameState):
        """
        Returns the expectimax action using self.depth and self.evaluationFunction

        All ghosts should be modeled as choosing uniformly at random from their
        legal moves.
        """
        def value(gameState, agentIndex, depth):
            if gameState.isWin() or gameState.isLose() or depth > self.depth:
                return self.evaluationFunction(gameState)
            if agentIndex == 0:
                
                return max_value(gameState, agentIndex, depth)
            else :
                return exp_value(gameState, agentIndex, depth)
        def max_value(gameState, agentIndex, depth):
            v = float("-inf")
            actions = gameState.getLegalActions(agentIndex)
            if depth ==1:
                bestAction=random.choice(actions)
                for action in actions:
                    successorState = (action,gameState.generateSuccessor(agentIndex, action))
                
                
                    tempV = value(successorState[1], agentIndex+1, depth)
                    if tempV>v:
                        v=tempV
                        bestAction = successorState[0]
                return bestAction
            else:
                for action in actions:
                    successorState = gameState.generateSuccessor(agentIndex, action)
                
                    v=max(v,value(successorState, agentIndex+1, depth))
                return v
        def exp_value(gameState, agentIndex, depth):
            v = 0.0
            actions = gameState.getLegalActions(agentIndex)
            for action in actions:
                successorState = gameState.generateSuccessor(agentIndex,action)
                p = 1.0 / len(actions)
                if agentIndex >= agentsNum-1:
                    v += p*value(successorState, 0, depth+1)
                else :
                    v += p*value(successorState, agentIndex+1, depth)
            return v
            
        agentsNum = gameState.getNumAgents()
        
        return max_value(gameState, 0, 1)

def betterEvaluationFunction(currentGameState):
    """
    Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
    evaluation function (question 5).

    DESCRIPTION: This function is well documented. I completed this by calculating distances from food and distances from ghosts.
    """
    #from searchAgents import mazeDistance
    
    score = 0.0 
    
    
    #food, the pacman always goes to the area where there are more food around.
    currentFood = currentGameState.getFood().asList()
    currentPos = currentGameState.getPacmanPosition()

    for food in currentFood:
        dtf= manhattanDistance(currentPos, food)
        #dtf= mazeDistance(currentPos, food, currentGameState)
        #this value means if the pacman is eager to eat food
        score += 1./dtf *1.1
    
    #ghost
    #the pacman does not like to go to the area where there is a ghost around.   
    
    ghostStates = currentGameState.getGhostStates()
    ghostState = ghostStates[0]
    ghost=ghostState.getPosition()
        
    #distanceToGhost = mazeDistance(currentPos, (int(ghost[0]),int(ghost[1])), currentGameState)
    distanceToGhost = manhattanDistance(currentPos, ghost)
    #this value means if the pacman is scared to the ghost. 
    score += -1./(distanceToGhost+1.0)         #distanceToGhost becomes 0 sometimes, I don't why. 
    
    
    #pellet
    #if the pacman and the ghost are near the pellet, the pacman will like to eat the pellet.
    capsulePositions = currentGameState.getCapsules()
    for cap in capsulePositions:
        dtp = manhattanDistance(currentPos, cap)
        dtg = manhattanDistance(ghost, cap)
        if dtp<5 and dtg<5:
            score += 1./dtp 
        
    #if the pacman has a distance which it is less than the ghost scaredtime, it will chase the ghost.
    time = ghostState.scaredTimer
    if distanceToGhost<time:
        score += 1./distanceToGhost
    
    #scores
    score += currentGameState.getScore()
        
    return score


# Abbreviation
better = betterEvaluationFunction
